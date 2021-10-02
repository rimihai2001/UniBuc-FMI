// Import packages
const express = require("express");
const morgan = require("morgan");
const bodyParser = require("body-parser");
const cors = require("cors");
const uuid = require("uuid");

const fs = require("fs");

// Aplicatia
const app = express();

app.use(express.static("Materials"));

// Middleware
app.use(morgan("tiny"));
app.use(bodyParser.json());
app.use(cors());

// Create
app.post("/bingos", (req, res) => {
  const bingosList = readJSONFile();
  const newBingo = req.body;
  newBingo.id = uuid.v4();
  const newBingoList = [...bingosList, newBingo];
  writeJSONFile(newBingoList);
  res.json(newBingo);
});

// Read One
app.get("/bingos/:id", (req, res) => {
  const bingosList = readJSONFile();
  const id = req.params.id;
  let idFound = false;
  let foundBingo;
  bingosList.forEach((bingo) => {
    if (id == bingo.id) {
      idFound = true;
      foundBingo = bingo;
    }
  });

  if (idFound) {
    res.json(foundBingo);
  } else {
    res.status(404).send(`Bingo ${id} was not found`);
  }
});

// Read All
app.get("/bingos", (req, res) => {
  const bingosList = readJSONFile();
  res.json(bingosList);
});

// Update
app.put("/bingos/:id", (req, res) => {
  const bingosList = readJSONFile();
  const id = req.params.id;
  const newBingo = req.body;
  newBingo.id = id;
  idFound = false;

  const newBingosList = bingosList.map((bingo) => {
    if (bingo.id == id) {
      idFound = true;
      return newBingo;
    }
    return bingo;
  });

  writeJSONFile(newBingosList);

  if (idFound) {
    res.json(newBingo);
  } else {
    res.status(404).send(`Bingo ${id} was not found`);
  }
});

// Delete
app.delete("/bingos/:id", (req, res) => {
  const bingosList = readJSONFile();
  const id = req.params.id;
  const newBingosList = bingosList.filter((bingo) => bingo.id != id);

  if (bingosList.length != newBingosList.length) {
    res.status(200).send(`Bingo ${id} was removed`);
    writeJSONFile(newBingosList);
  } else {
    res.status(404).send(`Bingo ${id} was not found`);
  }
});

// Functia de citire din fisierul db.json
function readJSONFile() {
  return JSON.parse(fs.readFileSync("db.json"))["bingos"];
}

// Functia de scriere in fisierul db.json
function writeJSONFile(content) {
  fs.writeFileSync(
    "db.json",
    JSON.stringify({ bingos: content }),
    "utf8",
    (err) => {
      if (err) {
        console.log(err);
      }
    }
  );
}

// Pornim server-ul
app.listen("3000", () =>
  console.log("Server started at: http://localhost:3000")
);
