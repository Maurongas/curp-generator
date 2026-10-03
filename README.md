# CURP Generator

A command-line program written in C that generates the **CURP** (Clave Unica de Registro de Poblacion), the 18-character population registry code used in Mexico, from a person's name, birth date, sex and state of birth.

It was built as a course project for *Structured Programming*, so everything is plain C99: functions, arrays and strings, with no external libraries.

## How the CURP is built

| Position | Content |
|----------|---------|
| 1        | First letter of the first surname |
| 2        | First internal vowel of the first surname (`X` if none) |
| 3        | First letter of the second surname (`X` if omitted) |
| 4        | First letter of the given name |
| 5-10     | Birth date as `YYMMDD` |
| 11       | Sex: `H` (male) or `M` (female) |
| 12-13    | State of birth code (e.g. `JC` for Jalisco, `NE` for born abroad) |
| 14-16    | First internal consonant of the first surname, second surname and given name |
| 17       | Differentiator: `0` for births up to 1999, `A` from 2000 on |
| 18       | Check digit |

Extra rules implemented:

- If the first four letters form an inconvenient word (list of 80 words), the second letter is replaced by `X`.
- Accented vowels are converted to plain vowels, and the symbols `/ - . _` become `X`.
- The check digit is computed with the official weighted-sum algorithm over the first 17 characters.
- Dates are validated, including leap years.

## Build and run

You need a C compiler such as `gcc` or `clang`.

```bash
make
./curp_generator
```

Without `make`:

```bash
gcc -std=c99 -Wall -Wextra -o curp_generator src/main.c
```

On Windows, use MinGW or WSL and run `curp_generator.exe`.

## Example session

```
FIRST SURNAME: Perez
PRESS ENTER TO SKIP
SECOND SURNAME (optional): Lopez
GIVEN NAME(S): Juan

YEAR OF BIRTH: 1990
MONTH OF BIRTH: 5
DAY OF BIRTH: 15
1. MALE
2. FEMALE

CHOOSE AN OPTION: 1

1. AGUASCALIENTES
2. BAJA CALIFORNIA
...
33. BORN ABROAD

CHOOSE THE STATE OF BIRTH: 14

CURP: PELJ900515HJCRPN03
```

## Project structure

```
src/
  main.c             entry point, runs the steps in order
  curp_fill.h        fills each position of the CURP
  curp_validate.h    vowel/consonant search, forbidden words, normalization
  input_utils.h      safe console input and range-checked numbers
  string_utils.h     hand-written string helpers
Makefile
```

## Known limitations

This is an educational project and it is not a replacement for the official RENAPO service.

- The generated CURP is for learning purposes only; the real homoclave (position 17) is assigned by RENAPO.
- Names starting with `MARIA` or `JOSE` should use the second name for positions 4 and 16. The helper `first_given_name` exists but its result is not wired in yet.
- Compound surnames with particles (`DE LA`, `DEL`, `VON`) are not skipped.
- The letter `N-tilde` is not converted to `X` in positions 14-16.
- Accent handling uses Latin-1 / Windows-1252 byte values. In a UTF-8 terminal, accented characters are dropped from the input, so type names without accents there.

## License

Released under the MIT License. See [LICENSE](LICENSE).
