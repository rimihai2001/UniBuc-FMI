var blackFridayCart = {
    telefon: "350",
    consola: "250",
    televizor: "450",
    iepurasPlus: "10.60",
    cercei: "20.34",
    geanta: "22.36"
  };
  
  function getCartValue(obj)
  {
    var sum = 0;
    for( var el in obj )
        sum += parseFloat(obj[el]);
    sum=Math.round(sum * 100) / 100
    console.log(sum);
  }
  
  getCartValue(blackFridayCart); // 1103.3