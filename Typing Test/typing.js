let para1 = "As we grow up, we learn that the one person who wasn't supposed to let you down probably will. You will have your heart broken, probably more than once, and it's never easier the  second time around. You'll break hearts too, so remember how it felt when yours was broken. You'll fight with your best friend, and may even fall in love with them. You'll blame a new love for things an old one did. You'll cry cause time is passing too fast. You'll eventually lose someone you love. Life is short, so take too many pictures, laugh way too much, kiss way too slow, cry way too hard, and love everyone.",
    para2 = "'I love you' means that I accept you for the person that you are, and that I do not wish to change you into someone else. It means that I will love you and stand by you even through the worst of times. It means loving you when you're in a bad mood or too tired to do things I want to do. It means loving you when you're down, not just when you're fun to be with. I love you means that I know your deepest secrets and do not judge you for them, asking in return only that you do not judge me for mine. It means that I care enough to fight for what we have and that I love you enough not to let go. It means thinking of you, dreaming of you, wanting and needing you constantly, hoping you feel the same way for me.",
    para3 = "I have been thinking a lot about growing up, and all of the relationships and broken hearts we go through. I always wonder how many times I said \"I love you\" to someone and knew I didn't mean it. It makes me think about all of the people that have said they love me and didn't mean it as well, and I get really pissed off, because I hate when people lie. I mean, if they were lying to get in my pants, that is one thing, but just for the sake of dragging this heart through the mud. I don't think anyone has ever used me for my body, and that really, really hurts. It really does. I want to be a booty call. Isn't that what we all want out of life; to be someone's \"go to\" sex slave? I forgot what I was talking about. Oh yeah, Love. Love sucks.",
    para4="Congratulations! You're not perfect! It's ridiculous to want to be perfect anyway. But then, everybody's ridiculous sometimes, except perfect people. You know what perfect is? Perfect is not eating or drinking or talking or moving a muscle or making even the teensiest mistake. Perfect is never doing anything wrong - which means never doing anything at all. Perfect is boring! So you're not perfect! Wonderful! Have fun! Eat things that give you bad breath! Trip over your own shoelaces! Laugh! Let somebody else laugh at you! Perfect people never do any of those things. All they do is sit around and sip weak tea and think about how perfect they are. But they're really not one-hundred-percent perfect anyway. You should see them when they get the hiccups! Phooey! Who needs 'em? You can drink pickle juice and imitate gorillas and do silly dances and sing stupid songs and wear funny hats and be as imperfect as you please and still be a good person. Good people are hard to find nowadays. And they're a lot more fun than perfect people any day of the week.",
    para5 = "Walking through the halls of high schools is quite similar to walking through a battle field you are never quite sure what you will find lying around the bend  everyone seems to be thinner, taller, blonder, prettier, and tanner than you, they all seem to be having the time of their lives despite the educational setting, they all seem to have the most friends and the most people to say hello to walking through the halls. Well, life isn't what it seems. Most of those people just surround themselves with others because they are too deathly scared to be alone. They are so scared that they aren't really friends, they just pretend because without those people they would be nothing. They hurt just like you do. They notice the imperfections in their own faces as well even though your eyes cannot see them. They notice how the girl next to them is taller and thinner even though you don't. Maybe sometimes it's what you don't see that makes you more alike than you'll ever know.";


let timeRemaining = 60;
let time = timeRemaining;



var startBtn = document.getElementById('startBtn');
var restartBtn = document.getElementById('restartBtn');
var modal = document.getElementById('modal');
var timerDiv = document.getElementById('timer');
var parentDiv = document.getElementById('container');
var testparagraph = document.getElementById('paraTextArea');
var typingArea = document.getElementById('typeTextArea');
var resultArea = document.getElementById('result');


startBtn.addEventListener('click',initiateTest);

restartBtn.addEventListener('click',restart);


function restart(){
    timeRemaining = time;
    resultArea.innerHTML = "";
    initiateTest();
    
    
    
}

function initiateTest (){
    typingArea.disabled = false;
    typingArea.value = "";
    modal.style.display = "none";
    timerDiv.innerHTML = "Time Remaining: " + timeRemaining + " sec ";
    parentDiv.classList.remove('hide');
    
    generateMessage();
    
    typingArea.addEventListener('keydown',startTimer);
    
}

function startTimer(){
    
    let timer = setInterval(function(){
        timeRemaining--;
        timerDiv.innerHTML = "Time Remaining: "+ timeRemaining +" sec" ;
        
        if (timeRemaining === 0){
            clearInterval(timer);
            typingArea.disabled = true;
            resultArea.innerHTML = "Your Speed: "+ calculateScore() + " Correct Words in " + time+ " sec.";
            
            
        }
    
    },1000);
    
    
    typingArea.removeEventListener('keydown',startTimer);
}


function generateMessage(){
        let para = [para1,para2,para3,para4,para5];
        
        testparagraph.innerHTML = para[Math.floor(Math.random()*5)];
        testparagraph.disabled = true;
}

function calculateScore(){
    let submittedText = typingArea.value;
    let providedText = paraTextArea.value;
    let wordCount =0;
    
    if(submittedText === ""){
        return 0;
    }
    else{
        submittedText = submittedText.trim();
        submittedText = submittedText.replace(/\n/g," ");
        providedText = providedText.trim();
        providedText = providedText.replace(/\n/g," ");
        let providedWords = providedText.split(" ");
        let submittedWords = submittedText.split(" ");
        for( let a in providedWords){
            if (providedWords[a] === submittedWords[a]){
                
                wordCount++;
            }
        }
        return wordCount;
    }
    
}