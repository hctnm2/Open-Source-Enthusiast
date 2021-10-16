from spellchecker import SpellChecker

spell = SpellChecker()
words = list()
word = input("Enter word")
words.append(word)

# find those words that may be misspelled
misspelled = spell.unknown(words)

for w in misspelled:
    # Get the one `most likely` answer
    print(spell.correction(w))

    # Get a list of `likely` options
    print(spell.candidates(w))
