const bgimg= document.querySelector('#bg_img');
const container= document.querySelector('.main_container');
const info= document.querySelector('.info');
const title= document.querySelector('#title');
const artists= document.querySelector('#artist');
const img_container= document.querySelector('.img_container');
const coverimg= document.querySelector('#cover');
const progress_bar= document.querySelector('.progress_bar');
const progress= document.querySelector('.progress');
const played_time= document.querySelector('#played_time');
const total_time= document.querySelector('#total_time');
const audio= document.querySelector('#gana');
const prev= document.querySelector('#prev');
const playbtn= document.querySelector('#play');
const next= document.querySelector('#next');

// Song titles and artists
const songs = ['Aai ni dekiru', 'Blue bird', 'Sparkle'];
const singer = ['Radwimps', 'Ikimono', 'Radwimps'];

// Keep track of song
let songIndex = 0;

// Update song details
function loadSong(song, name) 
{
  bgimg.src = `cover/${song}.jpg`;  
  title.innerText = song;
  artists.innerText = name;
  coverimg.src = `cover/${song}.jpg`;
  audio.src = `music/${song}.mp3`;
}

// play song

function playgana()
{
  container.classList.add('play');
  playbtn.querySelector('i.fas').classList.remove('fa-play');
  playbtn.querySelector('i.fas').classList.add('fa-pause');

  audio.play();
}

function pausegana()
{
  container.classList.remove('play');
  playbtn.querySelector('i.fas').classList.add('fa-play');
  playbtn.querySelector('i.fas').classList.remove('fa-pause');

  audio.pause();
}

// prev song

function prevgana()
{
  songIndex--;

  if(songIndex<0)
  {
    songIndex= songs.length -1;
  }

    loadSong(songs[songIndex], singer[songIndex]);

    playgana();
  
}

// next song

function nextgana()
{
  songIndex++;

  if(songIndex>songs.length -1)
  {
    songIndex= 0;
  }

    loadSong(songs[songIndex], singer[songIndex]);

    playgana();
  
}

//Updating total time

audio.addEventListener("loadeddata", ()=>{
  let totalmin = Math.floor(audio.duration / 60);
  let totalsec = Math.floor(audio.duration % 60);
  if(totalsec<10)
  {
    totalsec= `0${totalsec}`;
  }
  total_time.innerText= `${totalmin}:${totalsec}`;
})

//Updating progress bar

function progresstime(e)
{
  const {duration, currentTime} = e.srcElement;

  const widthpercent = (currentTime/duration)*100;
  progress.style.width = `${widthpercent}%`;

  // Updating current time

  let currmin = Math.floor(audio.currentTime / 60);
  let currsec = Math.floor(audio.currentTime % 60);
  if(currsec<10)
  {
    currsec= `0${currsec}`;
  }
  played_time.innerText= `${currmin}:${currsec}`;

}

function setbar(e)
{
  const width= this.clientWidth;
  const x= e.offsetX;
  const duration= audio.duration;
  audio.currentTime = (x/width)*duration;
}

// Event Listeners

playbtn.addEventListener('click' , () => {
  const playing = container.classList.contains('play');

  if(playing)
  {
    pausegana();
  }

  else
  {
    playgana();
  }
})

// Change song

prev.addEventListener('click', prevgana);
next.addEventListener('click', nextgana);

// Progress bar

audio.addEventListener('timeupdate', progresstime);
progress_bar.addEventListener('click', setbar);