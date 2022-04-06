-- Lists the names of all people who starred in Toy Story
SELECT people.name FROM people
JOIN movies, stars ON movies.id = stars.movie_id
AND people.id = stars.person_id
WHERE movies.title = "Toy Story";