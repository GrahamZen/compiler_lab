/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "syn_tree.y"


#include "translator.h"
#include <fstream>
extern int yyparse (void);
extern int yylex (void);
extern int yylineno;
extern void yyerror(char *s);
extern translator global_tab;
extern std::string tmpIdName;
extern std::string tmpTypeName;
extern std::map<string,int>type2size;
extern bool isTypeDef;
extern int funcArgNum;

#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Le = 258,
    Ge = 259,
    Eq = 260,
    Ne = 261,
    Def = 262,
    And = 263,
    Or = 264,
    IntConstant = 265,
    RealConstant = 266,
    REAL = 267,
    StringConstant = 268,
    Identifier = 269,
    Void = 270,
    INT = 271,
    WHILE = 272,
    If = 273,
    Else = 274,
    Return = 275,
    Operator = 276,
    BEGIN_KEY = 277,
    END_KEY = 278,
    MAIN = 279,
    WRITE = 280,
    READ = 281,
    RELOP = 282
  };
#endif
/* Tokens.  */
#define Le 258
#define Ge 259
#define Eq 260
#define Ne 261
#define Def 262
#define And 263
#define Or 264
#define IntConstant 265
#define RealConstant 266
#define REAL 267
#define StringConstant 268
#define Identifier 269
#define Void 270
#define INT 271
#define WHILE 272
#define If 273
#define Else 274
#define Return 275
#define Operator 276
#define BEGIN_KEY 277
#define END_KEY 278
#define MAIN 279
#define WRITE 280
#define READ 281
#define RELOP 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "syn_tree.y"

struct node* a;

#line 193 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

#define YYUNDEFTOK  2
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    30,    28,    34,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    31,    31,    31,    39,    40,    43,    43,    50,    50,
      51,    50,    60,    65,    69,    70,    71,    73,    79,    80,
      83,    84,    85,    88,    89,    90,    91,    92,    93,    94,
      95,   100,   105,   110,   113,   122,   123,   124,   127,   139,
     152,   154,   160,   160,   167,   175,   179,   181,   185,   188,
     194,   201,   210,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   234,   237,   238
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Le", "Ge", "Eq", "Ne", "Def", "And",
  "Or", "IntConstant", "RealConstant", "REAL", "StringConstant",
  "Identifier", "Void", "INT", "WHILE", "If", "Else", "Return", "Operator",
  "BEGIN_KEY", "END_KEY", "MAIN", "WRITE", "READ", "RELOP", "'+'", "'-'",
  "'*'", "'/'", "'('", "')'", "','", "';'", "$accept", "Programs", "$@1",
  "Program", "MethodDecl", "$@2", "$@3", "$@4", "$@5", "N", "O",
  "FormalParams", "FormalParam", "Block", "Statements", "Statement",
  "LocalVarDecl", "WhileStmt", "Type", "AssignStmt", "ReturnStmt",
  "IfStmt", "@6", "WriteStmt", "ReadStmt", "BoolExpression", "M",
  "Expression", "ActualParams", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    43,    45,
      42,    47,    40,    41,    44,    59
};
# endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,    20,   -65,   -65,   -65,    23,    49,   -65,   -65,   -65,
     -65,   -13,    26,    14,   -65,   -65,    31,    41,    49,   -65,
      -4,   -65,    60,   -65,    48,    49,   -65,    46,    59,   -65,
     -65,    49,    53,    94,   -65,    71,    11,     3,     4,   -65,
      83,   -65,   -65,   -65,    27,   -65,   -65,   -65,   -65,   -65,
      19,   -65,     5,    73,    11,    78,   -65,   -65,    90,    11,
      62,    79,    11,    80,   114,   -65,    82,    86,    24,   -65,
      48,   104,    81,    11,    -1,   103,   -65,    11,    96,    11,
      11,    11,    11,   -65,   -65,    89,   -65,   106,    53,   -65,
     -65,   -65,   -65,   -65,   -65,     1,   -65,   -65,   -65,    11,
     107,    34,   -65,    56,    56,   -65,   -65,   128,   129,   -65,
      11,    11,    82,   107,   -65,    11,   110,   111,    82,   -65,
     -65,   126,   107,   112,   113,   -65,   127,   -65,   -65,   -65,
      82,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    12,     1,     3,    12,     0,     5,    36,    37,
      35,     6,     0,     0,    13,     9,     0,     0,    16,    10,
       0,    15,     0,    13,     0,     0,    17,     0,     0,     7,
      14,    16,    19,     0,    52,     0,     0,     0,     0,    23,
      52,    21,    24,    30,     0,    25,    26,    27,    28,    29,
       0,    40,     0,     0,     0,     0,    57,    58,    59,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    41,    46,     0,    48,     0,     0,    20,
      33,    31,    11,    39,    38,     0,    52,    52,    52,     0,
      64,     0,    60,    53,    54,    55,    56,     0,     0,    52,
       0,     0,     0,    49,    61,     0,     0,     0,     0,    50,
      51,    44,    63,     0,     0,    34,     0,    45,    47,    52,
       0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   144,   -65,   -65,   -65,   -65,   -65,   -65,
     130,   119,   131,   -21,   -65,   -64,   -65,   -65,     8,   108,
     -65,   -65,   -65,   -65,   -65,   -60,   -40,   -35,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     4,     5,    12,    13,    17,    23,     6,
      16,    20,    21,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   126,    48,    49,    74,    53,    75,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    60,    89,    29,    61,    63,    55,    96,    97,    96,
      97,    -8,    55,    95,    11,    56,    57,    72,    71,    58,
       3,    56,    57,    -4,    78,    58,    22,    85,    67,    24,
      25,    52,    98,    22,   109,    62,    64,    59,    15,    22,
      14,    68,   100,    59,   103,   104,   105,   106,   121,    92,
     119,   120,    70,    25,   125,    19,   110,   111,   112,    91,
      32,     8,     9,    18,   113,    10,   131,   114,   115,   118,
      28,     8,     9,    33,    26,    10,    34,    35,    31,    36,
     122,    28,   -22,    88,    37,    38,    81,    82,    51,   130,
      79,    80,    81,    82,     8,     9,    33,    83,    10,    34,
      35,    52,    36,    54,    28,    73,    65,    37,    38,    79,
      80,    81,    82,    76,    84,    86,    94,    79,    80,    81,
      82,    90,    77,   107,    79,    80,    81,    82,    87,   102,
      99,    79,    80,    81,    82,    79,    80,    81,    82,    93,
     108,   116,   117,   123,   124,   -42,   129,   127,   128,     7,
      50,     0,    69,    27,     0,     0,    30
};

static const yytype_int16 yycheck[] =
{
      40,    36,    66,    24,     1,     1,     1,     8,     9,     8,
       9,    24,     1,    73,     6,    10,    11,    52,    13,    14,
       0,    10,    11,     0,    59,    14,    18,    62,     1,    33,
      34,     7,    33,    25,    33,    32,    32,    32,    24,    31,
      14,    14,    77,    32,    79,    80,    81,    82,   112,    70,
     110,   111,    33,    34,   118,    14,    96,    97,    98,    35,
       1,    12,    13,    32,    99,    16,   130,    33,    34,   109,
      22,    12,    13,    14,    14,    16,    17,    18,    32,    20,
     115,    22,    23,     1,    25,    26,    30,    31,    35,   129,
      28,    29,    30,    31,    12,    13,    14,    35,    16,    17,
      18,     7,    20,    32,    22,    32,    23,    25,    26,    28,
      29,    30,    31,    35,    35,    35,    35,    28,    29,    30,
      31,    35,    32,    34,    28,    29,    30,    31,    14,    33,
      27,    28,    29,    30,    31,    28,    29,    30,    31,    35,
      34,    13,    13,    33,    33,    19,    19,    35,    35,     5,
      31,    -1,    44,    23,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,    38,     0,    39,    40,    45,    39,    12,    13,
      16,    54,    41,    42,    14,    24,    46,    43,    32,    14,
      47,    48,    54,    44,    33,    34,    14,    46,    22,    49,
      48,    32,     1,    14,    17,    18,    20,    25,    26,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    59,    60,
      47,    35,     7,    62,    32,     1,    10,    11,    14,    32,
      63,     1,    32,     1,    32,    23,    62,     1,    14,    55,
      33,    13,    63,    32,    61,    63,    35,    32,    63,    28,
      29,    30,    31,    35,    35,    63,    35,    14,     1,    51,
      35,    35,    49,    35,    35,    61,     8,     9,    33,    27,
      63,    64,    33,    63,    63,    63,    63,    34,    34,    33,
      62,    62,    62,    63,    33,    34,    13,    13,    62,    61,
      61,    51,    63,    33,    33,    51,    58,    35,    35,    19,
      62,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    38,    37,    39,    39,    41,    40,    42,    43,
      44,    40,    45,    46,    47,    47,    47,    48,    49,    49,
      50,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    52,    53,    54,    54,    54,    55,    55,
      55,    56,    58,    57,    57,    59,    59,    60,    60,    61,
      61,    61,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     0,     9,     0,     0,
       0,    12,     0,     0,     3,     1,     0,     2,     3,     2,
       3,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     7,     1,     1,     1,     4,     4,
       2,     3,     0,    10,     6,     7,     3,     7,     3,     3,
       4,     4,     0,     3,     3,     3,     3,     1,     1,     1,
       3,     4,     2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 31 "syn_tree.y"
          {global_tab.tblSt.push(global_tab.t);global_tab.offsetSt.push(0);}
#line 1460 "y.tab.c"
    break;

  case 3:
#line 31 "syn_tree.y"
                                                                                   {global_tab.tblSt.top()->addwidth(global_tab.offsetSt.top());global_tab.tblSt.pop();global_tab.offsetSt.pop();
        ofstream codestm("test.ll");
        codestm<<global_tab.generator.postProcess()<<endl;
        ofstream symTabStm("symbolTable.txt");
        symTabStm<<global_tab.t<<endl;
    }
#line 1471 "y.tab.c"
    break;

  case 4:
#line 39 "syn_tree.y"
                     {}
#line 1477 "y.tab.c"
    break;

  case 5:
#line 40 "syn_tree.y"
                        {}
#line 1483 "y.tab.c"
    break;

  case 6:
#line 43 "syn_tree.y"
                  {tmpTypeName=(yyvsp[0].a)->typeName;}
#line 1489 "y.tab.c"
    break;

  case 7:
#line 43 "syn_tree.y"
                                                                                      {
        auto tmp=global_tab.tblSt.top();
        tmp->addwidth(global_tab.offsetSt.top());
        global_tab.tblSt.pop();
        global_tab.offsetSt.pop();
        global_tab.tblSt.top()->enterproc((yyvsp[-5].a)->idName,(yyvsp[-7].a)->typeName,tmp,(yyvsp[-2].a)->_typeStack);
    }
#line 1501 "y.tab.c"
    break;

  case 8:
#line 50 "syn_tree.y"
           {tmpTypeName=(yyvsp[0].a)->typeName;}
#line 1507 "y.tab.c"
    break;

  case 9:
#line 50 "syn_tree.y"
                                           {if(global_tab.t->mainDeclared)yyerror("error: main function is declared.");
        global_tab.t->mainDeclared=true;}
#line 1514 "y.tab.c"
    break;

  case 10:
#line 51 "syn_tree.y"
                                                    {if(global_tab.isDupVar((yyvsp[0].a)->idName))yyerrorStr("error: redefinition of '"+(yyvsp[0].a)->idName+'\'');}
#line 1520 "y.tab.c"
    break;

  case 11:
#line 52 "syn_tree.y"
    {
        auto tmp=global_tab.tblSt.top();
        tmp->addwidth(global_tab.offsetSt.top());
        global_tab.tblSt.pop();
        global_tab.offsetSt.pop();
        global_tab.tblSt.top()->enterproc((yyvsp[-6].a)->idName,(yyvsp[-10].a)->typeName,tmp,(yyvsp[-2].a)->_typeStack,true);
    }
#line 1532 "y.tab.c"
    break;

  case 12:
#line 60 "syn_tree.y"
              {auto t=mktable(global_tab.tblSt.top());
                global_tab.tblSt.push(t);
                global_tab.offsetSt.push(0);
                }
#line 1541 "y.tab.c"
    break;

  case 13:
#line 65 "syn_tree.y"
              {global_tab.generator.gen(tmpIdName);}
#line 1547 "y.tab.c"
    break;

  case 14:
#line 69 "syn_tree.y"
                                            {(yyval.a)=new node(yylineno,*(yyvsp[-2].a),(yyvsp[0].a)->typeName);}
#line 1553 "y.tab.c"
    break;

  case 15:
#line 70 "syn_tree.y"
                 {(yyval.a)=new node(yylineno,vector<string>({(yyvsp[0].a)->typeName}));}
#line 1559 "y.tab.c"
    break;

  case 16:
#line 71 "syn_tree.y"
                 {}
#line 1565 "y.tab.c"
    break;

  case 17:
#line 73 "syn_tree.y"
                             {global_tab.tblSt.top()->enter((yyvsp[0].a)->idName,(yyvsp[-1].a)->typeName,global_tab.offsetSt.top());global_tab.addwidth(type2size[(yyvsp[-1].a)->typeName]);
    (yyval.a)->typeName=(yyvsp[-1].a)->typeName;
    }
#line 1573 "y.tab.c"
    break;

  case 18:
#line 79 "syn_tree.y"
                                     {}
#line 1579 "y.tab.c"
    break;

  case 19:
#line 80 "syn_tree.y"
                       { yyerror("keyword typo?"); }
#line 1585 "y.tab.c"
    break;

  case 20:
#line 83 "syn_tree.y"
                                  {global_tab.backpatch((yyvsp[-2].a)->_nextlist,(yyvsp[-1].a)->_quad);(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1591 "y.tab.c"
    break;

  case 21:
#line 84 "syn_tree.y"
               {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1597 "y.tab.c"
    break;

  case 22:
#line 85 "syn_tree.y"
                 {}
#line 1603 "y.tab.c"
    break;

  case 23:
#line 88 "syn_tree.y"
                 {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1609 "y.tab.c"
    break;

  case 24:
#line 89 "syn_tree.y"
                  {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1615 "y.tab.c"
    break;

  case 25:
#line 90 "syn_tree.y"
                {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1621 "y.tab.c"
    break;

  case 26:
#line 91 "syn_tree.y"
                {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1627 "y.tab.c"
    break;

  case 27:
#line 92 "syn_tree.y"
            {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1633 "y.tab.c"
    break;

  case 28:
#line 93 "syn_tree.y"
               {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1639 "y.tab.c"
    break;

  case 29:
#line 94 "syn_tree.y"
              {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1645 "y.tab.c"
    break;

  case 30:
#line 95 "syn_tree.y"
               {(yyval.a)=new node(yylineno,*(yyvsp[0].a));}
#line 1651 "y.tab.c"
    break;

  case 31:
#line 100 "syn_tree.y"
                                   {
    global_tab.tblSt.top()->enter((yyvsp[-1].a)->idName,(yyvsp[-2].a)->typeName,global_tab.offsetSt.top());
    global_tab.addwidth(type2size[(yyvsp[-2].a)->typeName]);
    
    }
#line 1661 "y.tab.c"
    break;

  case 32:
#line 105 "syn_tree.y"
                       {if((yyvsp[-1].a)->typeName!=(yyvsp[0].a)->typeName){
        yyerrorStr("error: cannot convert ‘"+ (yyvsp[0].a)->typeName + "’ to ‘"+ (yyvsp[-1].a)->typeName + "’ in initialization");
    }
        global_tab.tblSt.top()->enter((yyvsp[0].a)->idName,(yyvsp[-1].a)->typeName,global_tab.offsetSt.top());
                        global_tab.addwidth(type2size[(yyvsp[-1].a)->typeName]);}
#line 1671 "y.tab.c"
    break;

  case 33:
#line 110 "syn_tree.y"
                     { yyerror("Maybe missing Identifier?"); }
#line 1677 "y.tab.c"
    break;

  case 34:
#line 113 "syn_tree.y"
                                                      {
    global_tab.backpatch((yyvsp[0].a)->_nextlist,(yyvsp[-5].a)->_quad);
    global_tab.backpatch((yyvsp[-3].a)->_truelist,(yyvsp[-1].a)->_quad);
    (yyval.a)=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>(*(yyvsp[-3].a)->_falselist));
    global_tab.generator.gen("goto", to_string((yyvsp[-5].a)->_quad));
}
#line 1688 "y.tab.c"
    break;

  case 35:
#line 122 "syn_tree.y"
          {isTypeDef=true;}
#line 1694 "y.tab.c"
    break;

  case 36:
#line 123 "syn_tree.y"
          {isTypeDef=true;}
#line 1700 "y.tab.c"
    break;

  case 37:
#line 124 "syn_tree.y"
                    {}
#line 1706 "y.tab.c"
    break;

  case 38:
#line 127 "syn_tree.y"
                                           {
    (yyval.a)=new node(yylineno, *(yyvsp[-3].a));
    (yyval.a)->typeName=(yyvsp[-1].a)->typeName;
    if(isTypeDef){global_tab.generator.gen("=",(yyvsp[-3].a)->idName,(yyvsp[-1].a)->_addr);isTypeDef=false;}
    else{
            auto typeName=global_tab.lookup((yyvsp[-3].a)->idName,0,false);
            if(typeName !=(yyvsp[-1].a)->typeName){
                yyerrorStr("error: cannot convert ‘"+ (yyvsp[-1].a)->typeName +"’ to ‘"+ typeName +"’ in assignment");
            }
            global_tab.generator.gen("=",(global_tab.lookup((yyvsp[-3].a)->idName,0).empty()?"":(yyvsp[-3].a)->idName),(yyvsp[-1].a)->_addr);
        }
    }
#line 1723 "y.tab.c"
    break;

  case 39:
#line 139 "syn_tree.y"
                                        {
        if(!isTypeDef){
            auto typeName=global_tab.lookup((yyvsp[-3].a)->idName,0,false);
            if(global_tab.lookup((yyvsp[-3].a)->idName,false) !=(yyvsp[-1].a)->typeName){
            yyerrorStr("error: cannot convert ‘"+ (yyvsp[-1].a)->typeName +"’ to ‘"+ typeName +"’ in assignment");
            }
        }
        (yyval.a)=new node(yylineno, *(yyvsp[-3].a));
        (yyval.a)->typeName=(yyvsp[-1].a)->typeName;
        global_tab.generator.gen("=",(yyvsp[-3].a)->idName,(yyvsp[-1].a)->idName);
        isTypeDef=false;
        }
#line 1740 "y.tab.c"
    break;

  case 40:
#line 152 "syn_tree.y"
                { yyerror("Maybe missing ';'?"); }
#line 1746 "y.tab.c"
    break;

  case 41:
#line 154 "syn_tree.y"
                                  {global_tab.generator.gen("return",(yyvsp[-1].a)->_addr);
    if((yyvsp[-1].a)->typeName!=tmpTypeName){
    yyerrorStr("error: no viable conversion from returned value of type '"+ (yyvsp[-1].a)->typeName +"' to function return type '"+tmpTypeName+'\'');
    }}
#line 1755 "y.tab.c"
    break;

  case 42:
#line 160 "syn_tree.y"
                                          {(yyval.a)=new node(yylineno,global_tab.nextQuad());(yyval.a)->_nextlist=mkList(global_tab.nextQuad());global_tab.generator.gen("goto","_");}
#line 1761 "y.tab.c"
    break;

  case 43:
#line 160 "syn_tree.y"
                                                                                                                                                                                                {
    (yyval.a)=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>(*(yyvsp[-4].a)->_nextlist));
    global_tab.backpatch((yyvsp[-7].a)->_truelist,(yyvsp[-5].a)->_quad);
    global_tab.backpatch((yyvsp[-7].a)->_falselist,(yyvsp[-1].a)->_quad);
    (yyval.a)->_nextlist->merge(*(yyvsp[-3].a)->_nextlist);
    (yyval.a)->_nextlist->merge(*(yyvsp[0].a)->_nextlist);
    }
#line 1773 "y.tab.c"
    break;

  case 44:
#line 167 "syn_tree.y"
                                           {
    (yyval.a)=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>(*(yyvsp[-3].a)->_falselist));
    global_tab.backpatch((yyvsp[-3].a)->_truelist,(yyvsp[-1].a)->_quad);
    (yyval.a)->_nextlist->merge(*(yyvsp[0].a)->_nextlist);
}
#line 1783 "y.tab.c"
    break;

  case 45:
#line 175 "syn_tree.y"
                                                           {(yyval.a)=new node(yylineno,global_tab.newTemp());
global_tab.generator.gen("param",(yyvsp[-4].a)->_addr);
global_tab.generator.gen("param",(yyvsp[-2].a)->idName);
global_tab.generator.gen("write","2");}
#line 1792 "y.tab.c"
    break;

  case 46:
#line 179 "syn_tree.y"
                      { yyerror("Maybe missing Identifier or StringConstant?"); }
#line 1798 "y.tab.c"
    break;

  case 47:
#line 181 "syn_tree.y"
                                                          {(yyval.a)=new node(yylineno,global_tab.newTemp());
global_tab.generator.gen("param",(yyvsp[-4].a)->idName);
global_tab.generator.gen("param",(yyvsp[-2].a)->idName);
global_tab.generator.gen("read","2");}
#line 1807 "y.tab.c"
    break;

  case 48:
#line 185 "syn_tree.y"
                     { yyerror("Maybe missing Identifier or StringConstant?"); }
#line 1813 "y.tab.c"
    break;

  case 49:
#line 188 "syn_tree.y"
                                            {
    (yyval.a)->_truelist=mkList(global_tab.nextQuad());
    (yyval.a)->_falselist=mkList(global_tab.nextQuad()+1);
    global_tab.generator.gen((yyvsp[-1].a)->idName,"_",(yyvsp[-2].a)->_addr,(yyvsp[0].a)->_addr);
    global_tab.generator.gen("goto","_");
}
#line 1824 "y.tab.c"
    break;

  case 50:
#line 194 "syn_tree.y"
                                         {
        (yyval.a)=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>());
        global_tab.backpatch((yyvsp[-3].a)->_truelist,(yyvsp[-1].a)->_quad);
        *(yyval.a)->_truelist=*(yyvsp[0].a)->_truelist;
        *(yyval.a)->_falselist=*(yyvsp[-3].a)->_falselist;
        (yyval.a)->_falselist->merge(*(yyvsp[0].a)->_falselist);
    }
#line 1836 "y.tab.c"
    break;

  case 51:
#line 201 "syn_tree.y"
                                        {
        (yyval.a)=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>());
        global_tab.backpatch((yyvsp[-3].a)->_falselist,(yyvsp[-1].a)->_quad);
        (yyval.a)->_truelist=(yyvsp[-3].a)->_truelist;
        (yyval.a)->_truelist->merge(*(yyvsp[0].a)->_truelist);
        (yyval.a)->_falselist=(yyvsp[0].a)->_falselist;
    }
#line 1848 "y.tab.c"
    break;

  case 52:
#line 210 "syn_tree.y"
               {(yyval.a)=new node(yylineno,global_tab.nextQuad());}
#line 1854 "y.tab.c"
    break;

  case 53:
#line 212 "syn_tree.y"
                                        {(yyval.a)=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("+",(yyval.a)->_addr,(yyvsp[-2].a)->_addr,(yyvsp[0].a)->_addr);(yyval.a)->typeName=typeExpand((yyvsp[-2].a)->typeName,(yyvsp[0].a)->typeName);}
#line 1860 "y.tab.c"
    break;

  case 54:
#line 213 "syn_tree.y"
                               {(yyval.a)=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("-",(yyval.a)->_addr,(yyvsp[-2].a)->_addr,(yyvsp[0].a)->_addr);(yyval.a)->typeName=typeExpand((yyvsp[-2].a)->typeName,(yyvsp[0].a)->typeName);}
#line 1866 "y.tab.c"
    break;

  case 55:
#line 214 "syn_tree.y"
                               {(yyval.a)=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("*",(yyval.a)->_addr,(yyvsp[-2].a)->_addr,(yyvsp[0].a)->_addr);(yyval.a)->typeName=typeExpand((yyvsp[-2].a)->typeName,(yyvsp[0].a)->typeName);}
#line 1872 "y.tab.c"
    break;

  case 56:
#line 215 "syn_tree.y"
                               {(yyval.a)=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("/",(yyval.a)->_addr,(yyvsp[-2].a)->_addr,(yyvsp[0].a)->_addr);(yyval.a)->typeName=typeExpand((yyvsp[-2].a)->typeName,(yyvsp[0].a)->typeName);}
#line 1878 "y.tab.c"
    break;

  case 57:
#line 216 "syn_tree.y"
                  {(yyval.a)=new node(yylineno,to_string((yyvsp[0].a)->intVal));(yyval.a)->typeName="INT";}
#line 1884 "y.tab.c"
    break;

  case 58:
#line 217 "syn_tree.y"
                   {(yyval.a)=new node(yylineno,to_string((yyvsp[0].a)->floatVal));(yyval.a)->typeName="REAL";}
#line 1890 "y.tab.c"
    break;

  case 59:
#line 218 "syn_tree.y"
                 {auto typeName=global_tab.lookup((yyvsp[0].a)->idName,0);(yyval.a)=new node(yylineno,(typeName.empty()?"":(yyvsp[0].a)->idName));(yyval.a)->typeName=typeName;}
#line 1896 "y.tab.c"
    break;

  case 60:
#line 219 "syn_tree.y"
                         {(yyval.a)=new node(yylineno,*(yyvsp[-1].a));(yyval.a)->typeName=(yyvsp[-1].a)->typeName;}
#line 1902 "y.tab.c"
    break;

  case 61:
#line 220 "syn_tree.y"
                                     {
        auto entry=global_tab.getEntry((yyvsp[-3].a)->idName,1);
        if(!entry||(yyvsp[-1].a)->_typeStack!=*entry->typeStack){
            yyerrorStr(string("error: no matching function for call to ") + (yyvsp[-3].a)->idName);
            (yyval.a)=new node(yylineno,global_tab.newTemp());
            global_tab.generator.gen("call",(yyval.a)->_addr,(yyvsp[-3].a)->idName,to_string(funcArgNum));
            funcArgNum=0;
        }else{
            (yyval.a)=new node(yylineno,global_tab.newTemp());
            (yyval.a)->typeName=entry->retType;
            global_tab.generator.gen("call",(yyval.a)->_addr,(yyvsp[-3].a)->idName,to_string(funcArgNum));
            funcArgNum=0;
        }
    }
#line 1921 "y.tab.c"
    break;

  case 62:
#line 234 "syn_tree.y"
                { yyerror("error: expected primary-expression before ‘;’ token"); }
#line 1927 "y.tab.c"
    break;

  case 63:
#line 237 "syn_tree.y"
                                           {global_tab.generator.gen("param",(yyvsp[0].a)->_addr);funcArgNum++;(yyval.a)->_typeStack.push_back((yyvsp[0].a)->typeName);}
#line 1933 "y.tab.c"
    break;

  case 64:
#line 238 "syn_tree.y"
                 {global_tab.generator.gen("param",(yyvsp[0].a)->_addr);funcArgNum++;(yyval.a)->_typeStack={(yyvsp[0].a)->typeName};}
#line 1939 "y.tab.c"
    break;


#line 1943 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 240 "syn_tree.y"
