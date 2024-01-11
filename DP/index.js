db.movies.aggregate([
  { $project: { _id: 0, genres: 1, imdb: 1, title: 1 } },
  { $unwind: "$genres" },
  { $group:
    { _id: "$genres",
      averageGenreRating: { $avg: "$imdb.rating" }
    }
  },
  { $sort: { averageGenreRating: -1 } },
  { $out : { db :"newDB" , coll:"newCollection"} }
] )