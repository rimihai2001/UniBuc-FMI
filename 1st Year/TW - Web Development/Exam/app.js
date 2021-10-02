const express = require("express");
const app = express();

app.use("/post", express.urlencoded({ extended: true }));

stoc = [
  {
    nume: "caiete",
    stoc: 3,
  },
  {
    nume: "creioane",
    stoc: 10,
  },
  {
    nume: "penare",
    stoc: 8,
  },
  {
    nume: "pixuri",
    stoc: 7,
  },
  {
    nume: "stilouri",
    stoc: 4,
  },
];

app.get("/p4.html", function (req, res) {
  res.sendFile(__dirname + "/p4.html");
});

app.post("/post", function (req, res) {
  
});

app.listen(3000, function () {
  console.log("Serverul pornit");
});
