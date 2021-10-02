function squareNumber(num) {
    var squaredNumber = num * num;
    return squaredNumber;
}

function halfOf(num) {
    var half = num / 2;
    return half;
}

function percentOf(num1, num2) {
    var percent = (num1/num2) * 100;
    return percent + '%';
}

function areaOfCircle(radius) {
    var area = Math.PI * squareNumber(radius);
    return area;
}

var squareButton = document.getElementById("square-button");
squareButton.addEventListener("click", function() {
  var num = document.getElementById("square-input").value;
  document.getElementById("solution").innerHTML = squareNumber(num);
});
    
var halfButton = document.getElementById("half-button");
halfButton.addEventListener("click", function() {
  var num = document.getElementById("half-input").value;
  document.getElementById("solution").innerHTML = halfOf(num);
});

var percentButton = document.getElementById("percent-button");
percentButton.addEventListener("click", function() {
  var num1 = document.getElementById("percent1-input").value;
  var num2 = document.getElementById("percent2-input").value;
  document.getElementById("solution").innerHTML = percentOf(num1, num2);
});

var areaButton = document.getElementById("area-button");
areaButton.addEventListener("click", function() {
  var num = document.getElementById("area-input").value;
  document.getElementById("solution").innerHTML = areaOfCircle(num);
});

var inputSquare = document.getElementById("square-input")
inputSquare.addEventListener("keypress", function (event) {
  if (event.keyCode == 13) {
    var num = document.getElementById("square-input").value;
    document.getElementById("solution").innerHTML = squareNumber(num);
  }
});
