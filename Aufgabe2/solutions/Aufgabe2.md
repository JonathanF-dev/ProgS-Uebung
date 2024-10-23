
# 2.1

Comment -> "(*" Char* "*)"
Comment -> "{" Char* "}"
Char -> Bel. Zeichen E Zeichensatz

Integer -> OktInt | DecInt | HexInt
Zero -> 0
OktInt -> Zero OktDigit (OktDigit | Zero)* IntType?
HexInt -> (0x | 0X) (HexDigit | Zero) (HexDigit | Zero)* IntType?
DecInt -> DecDigit (DecDigit | Zero)* IntType?
OktDigit -> 1 | 2 |3 | 4 | 5 | 6 | 7
DecDigit -> OktDigit | 8 | 9
HexDigit -> DecDigit | [a-f] | [A-F]
IntType -> u | U | l | L | ll | LL

# 2.2 -> Siehe PDF.

# 2.3 -> Siehe PDF

# 2.4

    public void parseB() {
      switch (LookAhead) {
      case Token.a:
      break;
      case Token.b:
        matchToken(Token.b);
        parseB();
      break;
      case Token.EndOfFile:
      break;
      default:
      throw new Exception();
      }
    }

# 2.5

-> Das else kann nicht eindeutig einem if zugeordnet werden. Das ist bekannt
als das "Dangling Else"-Problem. Ja, umschreiben geht, z.B. als (nur Auszug):

...
Statment -> MatchedStatment | UnmatchedStatment
MatchedStatment -> if (Expression) MatchedStatment else MatchedStatment | ...
UnmatchedStatment -> if (Expression) Statement | if (Expression) MatchedStatment else UnmatchedStatment
...

-> Hier Trennung zwischen Matched & Unmatched Statement, was effektiv bewirkt,
dass jedes 'else' mit dem nähesten vorherigen 'then' "gematched" wird.

# 2.6 -> Siehe Code

# 2.7

Nein, das geht nicht. Die Grammatik ist nicht LL sondern LR.

Umschreiben geht allerdings, z.B. so
(vgl. Beispiel id_list aus der Vorlesung):

(Hinweis: e -> leeres Wort)

expr -> term term_tail
term_tail -> add_op term term_tail | e
term -> factor factor_tail
factor_tail -> mult_op factor factor_tail | e
factor -> (expr) | id | number | - factor

Implementierung folgt noch...
