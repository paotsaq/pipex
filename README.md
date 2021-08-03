## C Pipes are very neat litle things... 👨‍💻

...hence, I bring you some notes that helped throughout the whole thing. This is, again, a 42 assignment, one where the piping mechanism of the shell must be replicated using C tools. It is an easy assignment to grasp, and it doesn't take very long - that is, if you debug it properly and make good decisions about your implementations (which I'm not really sure happened in this case).

### That is so cool! Did you read anything before doing the project, Alexandre? 📚

I did - Marshall Rosenberg's *Nonviolent Communication: A Language of Life: Life-Changing Tools for Healthy Relationships*, which seems like a great book for everything adult life tends to get mixed up into. It proposes a novel way to communicate, be it in the context of either personal or professional life, adopting efficient methods that bring clarity to everyday interactions. It's sort of like a mindful way to talk, which is great! But why do you ask? 🥰

### I mean, related to this particular project. I couldn't care less about your personal life.

Of course. Silly me!

It seems like [Code Vault](https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY) is a great video resouce on this, and has helped me immensely. So you should probably check that out; and, of course, the <code>man</code> pages for the allowed functions.

### Watching some videos is *not quite reading*, but I'll let that slide.

Thank you for your understanding. But I do have some tips regarding the project, too! 💡 Are you interested? 

### Oh, please do tell.

Since this is not Moulinette evaluted, I took some liberty with figuring out what the behaviour of the pipe is, in normal conditions. 

Mind you that:
	- if the <code>infile</code> doesn't exist, every command still runs, albeit with no input for the first command;
	- if the <code>outfile</code> doesn't exist, it must be created. New outfiles are created with <code>644</code> permissions, which is easy to overlook;
	- if the <code>outfile</code> exists, it gets overwritten, but the file keeps the same permissions it had before (granted it had, at least, read and write permissions).
	- if the <code>outfile</code> exists, but without the necessary permissions, the last command won't run.
	- if any of the commands in longer pipes (> 2 commands) do not exist or fail for any reason, a null input is fed onto the next command.

Other than this specific behaviour, there are some general tips: the <code>access</code> function is great to assess whether a file exists and/or has sufficient permissions; some commands are very useful for debugging, such as <code>mkdir</code>, or <code>touch</code>, because they produce palpable results. Of course, be wary to compare the built-in piping tool with your own.

I must again thank my friend Michele for having so much patience and wisdom - always such invaluable help ina ny project or programming endeavour. He alerted me to the usefulness of printing to STDERR, instead of STDOUT. Great advice! 
