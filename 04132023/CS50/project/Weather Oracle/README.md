#  Weather Oracle
## CS50 Final Project
#### Video Demo: https://www.youtube.com/watch?v=-xOReXV-MG4
#### Discription:
The Weather Oracle is an app that displays the current weather temperature in fahrenheit of any city a user searches for,
as well as a few details about the country that the city is located.

When a user enters the name of a city in the text field, they can either hit on the search magnifying glass, or hit the
return key on the keyboard to retrieve the information. Using the _Application Programing Interface_ from **OpenWeatherMaps.org**, methods in the **WeatherManager.swift** file are triggered and retrieves the weather data for that particular city from the openweathermaps website.

After the user initiates the search either through hitting the search icon or the Return key on the keyboard, the _endEditing_ function is called to clear the contents of the text field so that a new entry can be typed into it. Since the WeatherViewController conforms to the _textFieldDelegate_ protocol, the _textFieldDidEndEditing_ function gets triggered and that in turn gets the weatherManager object to call its _getWeather_ method. This method takes as its input, the city name entered by the user, appends it to the url from openweathermaps as well as an api key that the user registers for, to create a url which it will use to make a request for weather data.

The data retrieved from the site comes in json format with properties that are defined in the **WeatherData.swift** file. This file contains a struct called _WeatherData_ which conforms to the Decodable protocol. This allows it to be able to decode data from json format. It's properties include constants to store the country code, city name, temperature, a short description of the weather condition for the city, as well as its longitude and latitude coordinates. This json format will have to be converted to a swift object for it to work on the app. For this, I've created a WeatherModel.swift file.

The **WeatherModel.swift** file defines the properties that make up the
swift object that has been converted from the json object. It contains the properties that will be used to update the
user interface of the app.  One of its properties includes a computed property that returns a string that best describes the weather condition, this will be used to obtain an appropriate icon from Apple's _SFSymbols_ app, and updates the user interface with that icon.

A **Constant.swift** struct contains the api key that is needed to retrieve necessary data from openweathermaps. I have decided to save this in a separate file so that I have the option of not including it in my code when I upload it to a site such as _github.com_.

After the data has been converted from json to a swift object. The WeatherManager object calls its delegate - which is the WeatherViewController, and gets it to update the interface with the appropriate map, flag, and other relevant data.

The Weather Oracle app displays the temperature of the city being searched, in fahrenheit, the name of the city, as well
as the two-letter country code. It also shows a flag that represents the country where that city is located, as well as
displaying a map view of the city in non-satellite format. When the user clicks on the _more_ button, extra information
about the population of the country, its size in square meters, as well as its time zone is displayed. A dedicated _Location_ button at the top-left of the screen immediately gives information related to the user's current location.

Intended future improvements I have for this app is it's ability to give population and size information specific to the
city searched, as well as a satellite map view that paints a more accurate picture of weather conditions in that city.

**_This was my final project for CS50._**

