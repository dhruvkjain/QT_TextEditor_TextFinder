# Video showing app running
https://github.com/dhruvkjain/QT_TextEditor_TextFinder/assets/138356622/afdd1fb3-a46e-4dec-9a5f-1ffd8d4001df

## Note : 
Before using, add absolute path of 2input.txt inside textfinder.cpp 

## Important Takeaway :
Also, In Qt, when you attempt to open a resource file (indicated by the `:/` prefix), you cannot open it for writing (`QIODevice::ReadWrite`). Resource files are typically compiled into your application's binary and are read-only by default.
