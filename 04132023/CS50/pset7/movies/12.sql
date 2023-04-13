--Gets movie titles from the movies table
SELECT title FROM movies
--Gets those titles related to a list of movie_ids that the names Johnny Depp...
WHERE movies.id IN (SELECT movie_id FROM stars JOIN people ON people.id = stars.person_id WHERE name = "Johnny Depp")
--...and Helena Bonham Carter are connected to
AND movies.id IN (SELECT movie_id FROM stars JOIN people ON people.id = stars.person_id WHERE name = "Helena Bonham Carter");