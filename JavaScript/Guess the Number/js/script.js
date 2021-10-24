const number = document.querySelectorAll('div#num a')

const quest = document.querySelector('div#quest p')

const question = Math.round(Math.random() * 9)
console.log(question)

for (let index = 0; index < number.length; index++) {
    number[index].addEventListener('click', (e) => {
        e.preventDefault()

        for (let index = 0; index < 3; index++) {

            if (e.target.text < question) {
                return quest.innerHTML = 'Too small, try again !'

            } else if (e.target.text > question) {
                return quest.innerHTML = 'Too big, try again !'

            } else {
                quest.innerHTML = 'Correct !'
                setTimeout(() => {
                   const play = confirm('Play Again ?')
                   if (play) {
                    location.reload()
                }
                }, 500);

                break
            }
        }
    })
}
