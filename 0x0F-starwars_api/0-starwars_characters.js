#!/usr/bin/node

const request = require('request');
const arg = process.argv[2];
const req = 'https://swapi-api.hbtn.io/api/films/' + arg[0];

request(req, (error, responce, body) => {
  if (error) {
    return;
  }
  const res = JSON.parse(body);
  const namelst = {};
  res.characters.forEach(charurl => {
    request(charurl, (error, responce, body) => {
      if (error) {
        return;
      }
      const character = JSON.parse(body);
      namelst[character.url] = character.name;
      if (Object.keys(namelst).length === res.characters.length) {
        res.characters.forEach(charurl =>
          console.log(namelst[charurl]));
      }
    });
  });
});
