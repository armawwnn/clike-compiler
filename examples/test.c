int main(){
    switch (lexer->c) {
        case '=':
            return lexer_advance_current(lexer, TOKEN_EQUALS);
        case '(':

        case ')':
            return lexer_advance_current(lexer, TOKEN_RPAREN);

        case '{':
            return lexer_advance_current(lexer, TOKEN_LBRACE);

        case '}':
            return lexer_advance_current(lexer, TOKEN_RBRACE);

        case ':':
            return lexer_advance_current(lexer, TOKEN_COLON);

        case ',':
            return lexer_advance_current(lexer, TOKEN_COMMA);

        case '<':
            return lexer_advance_current(lexer, TOKEN_LT);

        case '>':
            return lexer_advance_current(lexer, TOKEN_GT);

        case ';':
            return lexer_advance_current(lexer, TOKEN_SEMI);
        case '\0':
            break;
        default:
            printf("unexpected chaarecter%c\n", lexer->c);
            exit(1);
            break;
    }
}
