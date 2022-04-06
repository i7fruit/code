/**
 * Lists the names of all people who have directed
 * a movie that received a rating of at least 9.0
 */
SELECT name FROM people JOIN movies, directors, ratings ON movies.id = directors.movie_id
AND movies.id = ratings.movie_id AND directors.person_id = people.id
WHERE ratings.rating >= 9.0;