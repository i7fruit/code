-- Lists the names of all people who starred in a movie released in 2004
SELECT name FROM people JOIN movies, stars ON movies.id = stars.movie_id
AND people.id = stars.person_id WHERE movies.year = 2004 ORDER BY people.birth;