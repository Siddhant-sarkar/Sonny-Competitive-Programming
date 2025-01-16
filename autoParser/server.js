const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');

const app = express();
const PORT = 12345;

// Get the output directory from environment variables or use a default
const OUTPUT_DIR = process.env.OUTPUT_DIR || path.join(__dirname, 'output');

// Ensure the output directory exists
if (!fs.existsSync(OUTPUT_DIR)) {
  fs.mkdirSync(OUTPUT_DIR, {recursive: true});
}

// Use body-parser middleware to parse JSON and URL-encoded payloads
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));

// Handle POST requests
app.post('/', (req, res) => {
  console.log('Received POST request with data:');
  console.log(req.body);  // Print the received data

  if (req.body && req.body.name && req.body.tests) {
    const cppFileName = `${req.body.name.replace(/\s+/g, '_')}.cpp`;
    const textFileName = `${req.body.name.replace(/\s+/g, '_')}_tests.txt`;

    // Write the C++ file
    const cppFilePath = path.join(OUTPUT_DIR, cppFileName);
    fs.writeFileSync(
        cppFilePath, '// Generated C++ file\n// Write your solution here\n',
        'utf8');
    console.log(`C++ file created: ${cppFilePath}`);

    // Write the tests to a text file
    const textFilePath = path.join(OUTPUT_DIR, textFileName);
    const testsContent = req.body.tests.map(test => test.input).join('\n');
    fs.writeFileSync(textFilePath, testsContent, 'utf8');
    console.log(`Tests file created: ${textFilePath}`);

    res.status(200).send('Files created successfully.');
  } else {
    res.status(400).send(
        'Invalid data. Ensure "name" and "tests" are present in the request body.');
  }
});

// Handle non-POST requests
app.all('*', (req, res) => {
  res.status(405).send('Only POST requests are allowed.');
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is listening on http://localhost:${PORT}`);
  console.log(`Output directory: ${OUTPUT_DIR}`);
});
