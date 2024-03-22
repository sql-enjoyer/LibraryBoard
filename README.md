# LibraryBoard
Simple console app for reading and editing bd.
Was built by mingw64.

### Main files:
**app.exe** - ready compiled file. **data.db** necessary for work.
**main.cpp** - main file with called classes.
**sqlite3.o** - obj sqlite file for work with db.
**data.db** - main db file with all library data. _Don't change his name._

### To compile programm by on one's own:
`g++ main.cpp sqlite3.o -o app`
