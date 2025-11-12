# 42cursus — 01 Libft

If you're getting the following error:  
```
(...) fatal error: bsd/string.h: No such file or directory
    2 | #include <bsd/string.h>
```
It means you don't have bsd installed on your system (are you running a WSL maybe?).  
In that case, you simply have to install bsd running `sudo apt install libbsd-dev`.