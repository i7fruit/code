--Gets names of actors from the people table
SELECT name FROM people
--gets those names' people ids from the stars table
WHERE id IN (SELECT person_id FROM stars
---checks the movie_ids that those people_ids are a part of
WHERE movie_id IN (SELECT movie_id FROM stars JOIN people ON stars.person_id =
--gets the list of movie_ids from the list of movie_ids that Kevin Bacon's name is a part of
(SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958)))
AND id != (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958);