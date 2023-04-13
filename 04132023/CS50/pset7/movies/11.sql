/**
 * Gets the titles of the five
 * highest rated movies Chadwick Boseman
 * starred in
 */
SELECT title FROM movies
JOIN people, stars, ratings
ON movies.id = ratings.movie_id
AND movies.id = stars.movie_id
AND people.id = stars.person_id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;