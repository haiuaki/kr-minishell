Function: **char \*readline (const char \*prompt)**

	Reads a line from the terminal and return it, using prompt as a prompt.
	If prompt is NULL or the empty string, readline does not issue a prompt.
	The line returned is allocated with malloc(3); the caller must free it when finished.


Function: **void add_history (const char \*string)**

	Add string to the end of the history list, and set the associated data field (if any) to NULL.
	If the maximum number of history entries has been set using stifle_history(), and the new number of history entries would exceed that maximum, this removes the oldest history entry.


Function: **void	rl_clear_history(void)**

	Clear the history list by deleting all of the entries, in the same manner as the History library’s clear_history() function.
	This differs from clear_history because it frees private data Readline saves in the history list. 


Function: **int	rl_on_new_line(void)**

	Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline. 


Function: **void	rl_replace_line(const char \*text, int clear_undo)**

	Replace the contents of rl_line_buffer with text. This preserves the point and mark, if possible.\
	If clear_undo is non-zero, this clears the undo list associated with the current line. 


Function: **void	rl_redisplay(void)**

	Change what's displayed on the screen to reflect the current contents of rl_line_buffer. 

---

**sigaction()** (POSIX) is better than **signal()** (C Standard)<br>
```
struct sigaction {
	void		(*sa_handler)(int);
	void		(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t	sa_mask;
	int			sa_flags;
	void		(*sa_restorer)(void);
};
```

**sa_handler** is pointer to a function that will handle the signal.<br>
**sa_sigaction** is not compatible with **sa_handler**, we can't specify both.<br>
Hence we need to make sure all the bits in the structure are initialized to zero.<br>
**sa_mask** allows to block specific signals during the handler's execution.<br>
**sa_flags** offers different options to modify the signal action.<br>