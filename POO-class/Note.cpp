for (size_t i = 0; i < content.size(); i++)
{
    char ** str = & content[i];
    char result[this->fileSize];

    // Cmt let's know us if we have a '/*' open and we wait to close it
    bool cmt = false;
    bool lcmt = false;

    for ( char *p = *str ; *p != '\n' ; p++ )
    {
        *(p++)
        if( get(*p) == '/' )
        {
            switch( get(*(p+1)) )
            {
                case '/':
                    lcmt = true;
                    p++;
                    break;
                case '*':
                    cmt = true;
                    p++;
                    break;
                default:
                    break;
            }

        }
    }
}

// Function to translate char and avoid problem
char get( char c ){
    if (c >= ' ' || c == '\n') {
        return c;
    }
    if (c == '\r') {
        return '\n';
    }
    return ' ';
}