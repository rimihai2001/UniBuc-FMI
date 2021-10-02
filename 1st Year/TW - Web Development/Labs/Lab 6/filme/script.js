var array=[
{
    title: "The Da Vinci Code",
    duration: 174,
    actors: ['Tom Hanks','Ian McKellen'],
    viewed: true,
    img_link: 'https://i.pinimg.com/474x/ce/e9/c2/cee9c2c76ba3cdc89a98328075f0c24b.jpg'
},
{
    title: "Inferno",
    duration: 121,
    actors: ['Tom Hanks','Felicity Jones'],
    viewed: true,
    img_link: 'https://i.ytimg.com/vi/cO--qfH69Qc/movieposter.jpg'
},
{
    title: "Bohemian Rhapsody",
    duration: 133,
    actors: ['Rami Malek','Brian May'],
    viewed: false,
    img_link: 'https://pbs.twimg.com/profile_images/1080450214807298048/QUetVW1e.jpg'
}
]

for(film=0; film<array.length; film++)
{
    const new_p=document.createElement("p");
    new_p.innerText=array[film].title;
    const new_p2=document.createElement("p");
    new_p2.innerText=array[film].duration;
    const new_p3=document.createElement("p");
    new_p3.innerText=array[film].actors;
    const imagine=document.createElement("img");
    imagine.src=array[film].img_link;
    document.body.appendChild(new_p);
    document.body.appendChild(new_p2);
    document.body.appendChild(new_p3);
    document.body.appendChild(imagine);
}

const new_ul = document.createElement("ul");
for(film of array)
{
    const new_li=document.createElement("li");
    if(film.viewed)
    {
       new_li.classList.add('film-viewed');
    }
    const new_p=document.createElement("p");
    new_p.innerText=film.title;
    new_li.appendChild(new_p);

    const imagine=document.createElement("img");
    imagine.src=film.img_link;
    new_li.appendChild(imagine);

    new_ul.appendChild(new_li);
    document.body.appendChild(new_ul);
}