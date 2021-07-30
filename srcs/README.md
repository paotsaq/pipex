## pipes are very neat litle things... 👨‍💻

...hence, I bring you some notes that helped throughout the whole thing. This is, again, a 42 assignment.

### Did you read anything before doing the project, Alexandre?

I did - I am halfway through *Nonviolent Communication: A Language of Life: Life-Changing Tools for Healthy Relationships*, which seems like a great book for everything adult life tends to get mixed up into. But why do you ask?

### I mean, related to this particular project. I couldn't care less about your personal life.

Of course. Silly me!

It seems like [Code Vault](https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY) is a great video resouce on this, and has helped me immensely. So you should probably check that out!

### Watching some videos is *not quite reading*, but I'll let that slide.

Thank you for your understanding. But I do have some tips regarding the project, too! Are you interested?

### Oh, please do tell.

Since this is not Moulinette evaluted, I took some liberty with figuring out what the behaviour of the pipe is, in normal conditions. 

Mind you that:
	- if the <code>infile</code> doesn't exist, every command still runs, albeit with no input for the first command;
	- if the <code>outfile</code> doesn't exist, it must be created. New outfiles are created with <code>644</code> permissions, which is easy to overlook;

