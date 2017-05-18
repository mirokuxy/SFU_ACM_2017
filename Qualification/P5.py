import sys

Vowels = set(['a','A','e','E','i','I','o','O','u','U'])

def is_vowel(ch):
  return ch in Vowels

def is_consonant(ch):
  return ch.isalpha() and not is_vowel(ch)

def print_word(word, consonant):
  print(''.join(word), end='')
  if consonant:
    print(consonant, end='')
  print('ay', end='')

for line in sys.stdin:
  word, consonant = [], None

  for ch in line:
    if is_vowel(ch):
      word.append(ch)
    elif is_consonant(ch):
      if word or consonant:
        word.append(ch)
      else:
        consonant = ch
    else:
      if word or consonant:
        print_word(word, consonant)
        word, consonant = [], None
      print(ch, end='')
  
  # check stored word
  if word or consonant:
    print_word(word, consonant)
    word, consonant = [], None




