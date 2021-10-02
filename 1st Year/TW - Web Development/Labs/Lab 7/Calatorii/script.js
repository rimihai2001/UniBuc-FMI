function makeStory() {
    var story = document.getElementById("story");
    var person = document.getElementById("person").value;
    var adjective = document.getElementById("adjective").value;
    var noun = document.getElementById("places").value;
    story.innerHTML = person + " a vizitat " + adjective + " " + noun + ".";
  }
  
  var storyButton = document.getElementById('story-button');
  storyButton.addEventListener('click', makeStory);