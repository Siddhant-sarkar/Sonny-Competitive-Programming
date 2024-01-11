import subprocess
import requests
from bs4 import BeautifulSoup as bb
from urllib.request import urlopen, Request
import time
import json

usernae = input('Enter the username which u wnat to copy submissions from. ')
res = requests.get(f'https://codeforces.com/api/user.status?handle={usernae}&from=1&count=1000')
contest = []
sub = []
clk = []
qname = []
def get_accepted_submision():
    # print(res.json()['result'][])
    cnt = 0
    for x  in res.json()['result']:
        # print(x['problem']['rating'])
        if(x['verdict'] == 'OK' and cnt >=2 and  x['problem']['rating'] ==1700) :
            sub.append(x['id'])
            contest.append(x['problem']['contestId'])
            clk.append(x['problem']['index'])
            qname.append(x['problem']['name'])
        cnt = cnt +1
    print("succesfully retrived all the ids")
    return sub;


def save_submission(id,const,ind):
    k = f'https://codeforces.com/contest/{const}/submission/{id}';
    req = Request(
    url=k, 
    headers={
            'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.84 Safari/537.36',
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
            'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
            'Accept-Encoding': 'none',
            'Accept-Language': 'en-US,en;q=0.8',
            'Connection': 'keep-alive',
            'refere': 'https://example.com',
            'cookie': """your cookie value ( you can get that from your web page) """
            }
    )
    page = urlopen(req).read().decode("utf-8")
    soup = bb(page,"html.parser")
    ar = soup.find(id="program-source-text")
    with open(f'{const}{ind}.cpp', 'w') as f:
        for line in ar.string:
            f.write(line)
    f.close()

get_accepted_submision();
cnt  =  0;
# k = qname.index('Hossam and Friends');
# print(k)

# print(sub[183],contest[183]);
for i  in range(len(sub)):
    if(cnt != 0 and  cnt %20 == 0):
        print("going to sleep for 5 mins . zzz zzz zzz")
        time.sleep(300);
    save_submission(sub[i],contest[i],clk[i]);
    subprocess.run(f'cft submit {contest[i]}{clk[i]}',shell=True);
    subprocess.run(f'rm {contest[i]}{clk[i]}.cpp',shell=True);
    cnt += 1;
