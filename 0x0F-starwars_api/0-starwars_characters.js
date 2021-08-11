#!/usr/bin/nodes

const request = require('request');
const arg = process.argv[2];
const req = 'https://swapi-api.hbtn.io/api/films/' + arg[0];

request(req, (error, responce, body) => {
  const res = JSON.parse(body);
  const namelst = {};
  res.characters.forEach(char_url => {
    request(char_url, (error, responce, body) => {
      const character = JSON.parse(body);
      namelst[character.url] = character.name;
      if (Object.keys(namelst).length === res.characters.length) {
        res.characters.forEach(char_url =>
          console.log(namelst[char_url]));
      }
    });
  });
});
