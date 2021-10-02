document.body.style.fontFamily="Arial, sans-serif";

const nickname_element=document.getElementById("nickname");
const favorites_element=document.getElementById("favorites");
const ht_element=document.getElementById("hometown");

nickname_element.innerText='RMI';
favorites_element.innerText='LFC';
ht_element.innerText='Bucharest';

li_items=document.getElementsByTagName("li");

for(elem of li_items)
{
    elem.classList.add("list-item");
}

const imagine=document.createElement("img");
imagine.src="https://media-exp1.licdn.com/dms/image/C4E03AQEKF4T2nFA9qg/profile-displayphoto-shrink_200_200/0/1599744692186?e=1622073600&v=beta&t=ouRHSEhQE0wL3pWL5DYLn_Kia-gmwFNNoE22UIT9qmI";
document.body.appendChild(imagine);