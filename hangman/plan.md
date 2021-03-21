# rough control flow

main() -> generateWord() -> getRandomNumber() -> return word to main() -> pass word to getGuess() -> displayCurrentCorrect() -> loop between getGuess and displayCorrect 6 times -> give result to main() -> result passed to returnResults() -> main() return 0

## how to draw the hangman

inside the displayCurrentCorrect() have 6 different multiline strings. To declare a multiline string use:
const string str =
R"(
"Line 1
Line 2
and so on"
)";
