The four languages used in this course, C, bash, Perl, and python, have many similarities and differences. 
They all use the same Algol family syntax and code structures, if, for, while, etc. This means that it 
is relatively simple to switch between them, the main differences are when and where to put or not put braces. 
The syntax and thought process of this style of imperative programming is different to declarative styles used by
languages like Lisp and Haskell. 

They all also support using regexs, giving you access to a shared powerful tool for
dealing with text. The regex engines do support different features so you need to be careful when using them.
They are also all under open source licenses. The fact that they are open source means that you can modify the 
language to suit your needs or contribute to improvements. It also means that when you run into trouble there 
is a community to help resolve your issue.

The biggest and most immediate difference for each language is its syntax. C and Perl use braces to denote blocks, 
bash uses keywords, and python uses indentation. Perl and C use semicolons at the end of statements while bash and
python use line breaks. Each language also has a different approach to variables. C is statically typed and checked 
at compile time, bash and Perl both have all their variables as strings that can be treated as numbers as needed,
python has a similar static type system to C, but it is checked at runtime and is less strict, an object just needs
to implement the required methods to be used instead. Unlike the others, bash doesn't have a true class system.

Each language is also used for a different purpose. C is meant for lower level systems, Bash is for relatively simple
shell scripts, Perl is for text processing, and Python is a general purpose language. Related to this is each language's
approach to memory management and speed. C is compiled and therefore quite fast compared to the interpreted scripts. 
As part of it's speed, C requires the programmer to manage memory, while the others use a garbage collector. The garbage
collector slows the language down.

I have things that I like and dislike about each language, and would choose each for a different purpose. I would place
Perl as my least favorite. I do prefer the syntax to bash, but because all the variables are strings, many of the things
you can do in it are better performed in a language like python or C. I would place bash next. I really dislike the 
keyword syntax for defining blocks, like endif. It is very useful for gluing other programs together and automating
processes, I frequently use it to make compiling and running programs one command.

Of these four, my second favorite is C. The syntax is pretty nice, I prefer brackets to keywords and there isn't too much
redundancy. I don't think that semicolon's at the end of statements is necessary and newlines should be used instead. 
I like that is it compiled and quite fast, but I don't think manual memory management is worth the speed increase on
modern computers. That leaves Python as my favorite. I have used it quite a lot and it is very flexible. By default it
feels dynamically typed, but can be more static if you choose. The syntax has very little redundancy, and blocks defined
by indentation forces you to make better looking code than braces. 
