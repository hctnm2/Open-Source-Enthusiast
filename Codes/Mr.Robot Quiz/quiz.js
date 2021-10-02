
const questions = [
    {
      quest: " Where Does Elliot work ? ",
      answer: "2",
      options: ["Cisco", "Everything Safe","AllSafe","Evil Corps"],
    },
    {
      quest: "What made Elliot live isolated from other people?",
      answer: "0",
      options: ["Social anxiety disorder", "Hacktivists", "Fear", "Debt"],
    },
    {
      quest: "What's Elliot's dog called?",
      answer: "2",
      options: ["Bella", "Slipper", "Flipper", "Dognut"],
    },
    {
      quest: "Who Said This Line: 'Power Belongs To Those Who Take It.'?",
      answer: "3",
      options: ["Terry Colby", "Whiterose", "Mr.Robot", "Tyrell Wellick"],
    },
  ];
  const ques = document.querySelector(".quest");
  const opt = document.querySelectorAll(".opt");
  const nxt = document.querySelector(".next");
  
  let i = 0;
  let score = 0;
  // console.log(ques, btn, opt, opt[0])
  
  let question = questions[i];
  ques.innerHTML = `${i + 1}. ${question.quest}`;
  opt[0].innerHTML += "a-> " + question.options[0];
  opt[1].innerHTML += "b-> " + question.options[1];
  opt[2].innerHTML += "c-> " + question.options[2];
  opt[3].innerHTML += "d-> " + question.options[3];
  let flag = false;
  
  nxt.addEventListener("click", () => {
    i += 1;
    if (i === questions.length) {
      alert("Quiz Completed");
      window.location.reload();
    }
    let question = questions[i]; //
    ques.innerHTML = `${i + 1}. ${question.quest}`;
    opt[0].innerHTML = "a => " + question.options[0];
    opt[1].innerHTML = "b => " + question.options[1];
    opt[2].innerHTML = "c => " + question.options[2];
    opt[3].innerHTML = "d => " + question.options[3];
  });
  
  let y = document.getElementsByTagName("button");
  console.log(y);
  for (let j = 0; j < y.length - 1; j++) {
    let item = y[j];
    item.addEventListener("click", () => {
      let ans = item.getAttribute("id");
      console.log(ans);
      let question = questions[i];
      if (question.answer === ans) {
        score++;
        alert(`Correct answer. Your score is ${score}`);
      } else alert("Wrong answer");
    });
  }