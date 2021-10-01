function createAnagram(str1, str2) {
    let countChar = 0;
    const arrStr2 = str2.split("");
    for(let str of str1){
        let idx = arrStr2.findIndex(s => s === str);
        if(idx >= 0){
            ++countChar;
            arrStr2.splice(idx, 1);
        }
    }

    return (str1.length - countChar) + (str2.length - countChar);
}

console.log(createAnagram("dce", "efc"))
console.log(createAnagram("cdfea", "afbbk"))
console.log(createAnagram("adkrn", "r"))
