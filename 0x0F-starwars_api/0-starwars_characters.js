#!/usr/bin/node

const request = require('request');

const id = process.argv[1];const starWarsCharacters = new Promise((resolve, reject) => {
  request.get(
    `https://swapi-api.hbtn.io/api/films/${id}`,
    (error, response, body) => {
      if (error) {
        reject(error.message);
      }
      body = JSON.parse(body);
      resolve(body.characters);
    }
  );
});

const getCharacters = async () => {
  const character = await starWarsCharacters;
  character.forEach(element => {
    request.get(element, (error, response, body) => {
      if (error) { console.log(error.message); }
      body = JSON.parse(body);
      console.log(body.name);
    })
  });
}

getCharacters();
