-- 1. Extracts information about where the crime took place as well as the date
SELECT * FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";

/* 2. Extracts the names of the witnesses as well as their interview transcripts from the Interviews table
where the date equals the date of the theft, and the transcripts contain the word "theif" */
SELECT name, transcript  FROM interviews WHERE year = 2020 AND month = 7 AND day = 28 AND (transcript LIKE "%thief%");


/* 3. Extracts people who's cars were at the courthouse during the time of the theft */
SELECT people.name FROM courthouse_security_logs
JOIN people ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25);

/* 4. ATM withdrawals on Fifer Street */
SELECT *, people.name FROM atm_transactions
JOIN bank_accounts, people ON bank_accounts.account_number = atm_transactions.account_number
AND bank_accounts.person_id = people.id
WHERE year = 2020 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Fifer Street";

-- 5. Calls made from courthouse for less than a minute
SELECT DISTINCT(phone_calls.caller), people.name FROM phone_calls -- Gets phone numbers of people who...
JOIN people ON phone_calls.caller = people.phone_number

WHERE people.phone_number IN (SELECT DISTINCT(people.phone_number) FROM courthouse_security_logs -- ...from the courthouse...
JOIN people ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25)) -- ...within the timeframe of the theft...

AND phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60; -- ...made a call that lasted less than a minute.


-- 6. Which of the callers made an atm withdrawal on Fifer Street?
SELECT name FROM people -- Gets the names...
WHERE name IN

(SELECT DISTINCT(people.name) FROM phone_calls -- ...and phone numbers...
JOIN people ON phone_calls.caller = people.phone_number

WHERE people.phone_number IN (SELECT DISTINCT(people.phone_number) FROM courthouse_security_logs -- ...of callers from the courthouse
JOIN people ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25)) -- ...within timeframe of theft...

AND phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60) --...that made call lasting less than a minute

AND people.name IN

(SELECT DISTINCT(people.name) FROM atm_transactions -- ...who later made an ATM withdrawal on Fifer Street
JOIN bank_accounts, people ON bank_accounts.account_number = atm_transactions.account_number
AND bank_accounts.person_id = people.id
WHERE year = 2020 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Fifer Street");


-- 7. Earliest flight out of town the next day
SELECT origin_airport_id, destination_airport_id, hour, minute FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE year = 2020 AND month = 7 AND day = 29);



-- 8. Which one of names in step 6, took the earliest flight out, and to what destination?
SELECT people.name, airports.city FROM people JOIN flights, passengers, airports ON
flights.id = passengers.flight_id AND
airports.id =

-- Gets destination that earliest flight will fly to
(SELECT destination_airport_id FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE year = 2020 AND month = 7 AND day = 29))

AND
people.passport_number = passengers.passport_number
WHERE people.name IN

-- From 6. Which of the callers made an atm withdrawal on Fifer Street?
(SELECT name FROM people -- Gets the names...
WHERE name IN

(SELECT DISTINCT(people.name) FROM phone_calls -- ...and phone numbers...
JOIN people ON phone_calls.caller = people.phone_number

WHERE people.phone_number IN (SELECT DISTINCT(people.phone_number) FROM courthouse_security_logs -- ...of callers from the courthouse
JOIN people ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25)) -- ...within timeframe of theft...

AND phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60) --...that made call lasting less than a minute

AND people.name IN

(SELECT DISTINCT(people.name) FROM atm_transactions -- ...who later made an ATM withdrawal on Fifer Street
JOIN bank_accounts, people ON bank_accounts.account_number = atm_transactions.account_number
AND bank_accounts.person_id = people.id
WHERE year = 2020 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Fifer Street"))

AND flight_id IN

-- From 7. Earliest flight out of town the next day
(SELECT flights.id FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE year = 2020 AND month = 7 AND day = 29));


/* STEP 9 TO GET ACCOMPLICE */
--Gets people who recieved phone calls within timeframe of theft
SELECT * FROM people WHERE phone_number IN
(-- 5. Calls made from courthouse for less than a minute
SELECT DISTINCT(phone_calls.receiver) FROM phone_calls -- Gets phone numbers of people who...
JOIN people ON phone_calls.caller = people.phone_number

WHERE people.phone_number IN (SELECT DISTINCT(people.phone_number) FROM courthouse_security_logs -- ...from the courthouse...
JOIN people ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25)) -- ...within the timeframe of the theft...

AND phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60); -- ...made a call that lasted less than a minute.


-- Step 10 Extracts the name of the accomplice
SELECT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number -- Gets number of person who received call...

WHERE phone_calls.caller =

(-- From 8. Which one of names in step 6, took the earliest flight out, and to what destination?
SELECT people.phone_number FROM people JOIN flights, passengers, airports ON -- ...from the phone number that the thief called from.
flights.id = passengers.flight_id AND
airports.id =

-- Gets destination that earliest flight will fly to
(SELECT destination_airport_id FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE year = 2020 AND month = 7 AND day = 29))

AND
people.passport_number = passengers.passport_number
WHERE people.name IN

-- From 6. Which of the callers made an atm withdrawal on Fifer Street?
(SELECT name FROM people -- Gets the names...
WHERE name IN

(SELECT DISTINCT(people.name) FROM phone_calls -- ...and phone numbers...
JOIN people ON phone_calls.caller = people.phone_number

WHERE people.phone_number IN (SELECT DISTINCT(people.phone_number) FROM courthouse_security_logs -- ...of callers from the courthouse
JOIN people ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25)) -- ...within timeframe of theft...

AND phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60) --...that made call lasting less than a minute

AND people.name IN

(SELECT DISTINCT(people.name) FROM atm_transactions -- ...who later made an ATM withdrawal on Fifer Street
JOIN bank_accounts, people ON bank_accounts.account_number = atm_transactions.account_number
AND bank_accounts.person_id = people.id
WHERE year = 2020 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Fifer Street"))

AND flight_id IN

-- From 7. Earliest flight out of town the next day
(SELECT flights.id FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE year = 2020 AND month = 7 AND day = 29)))




AND phone_calls.receiver IN

(/* TO GET ACCOMPLICE */
--Gets people who recieved phone calls within timeframe of theft
SELECT people.phone_number FROM people WHERE phone_number IN
(-- 5. Calls made from courthouse for less than a minute
SELECT DISTINCT(phone_calls.receiver) FROM phone_calls -- Gets phone numbers of people who...
JOIN people ON phone_calls.caller = people.phone_number

WHERE people.phone_number IN (SELECT DISTINCT(people.phone_number) FROM courthouse_security_logs -- ...from the courthouse...
JOIN people ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25)) -- ...within the timeframe of the theft...

AND phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60)); -- ...made a call that lasted less than a minute.