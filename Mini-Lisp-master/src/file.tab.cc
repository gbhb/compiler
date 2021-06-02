/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "file.yy" /* yacc.c:339  */

    #include<iostream>
    #include<cstdlib>
    #include "AST.h"
    #include<map>
    #include<cstring>
    #include<stack>
    #include<vector>
    
    extern int yylex(void);
    void yyerror(const char *msg);
    typedef std::map<std::string, ASTNode *> Map;
    Map* def;
    Map::iterator iter;
    std::stack<ASTType> operation;
    ASTNode *root;
    int ASTArith(ASTNode *, Map *map);
    bool ASTLogical(ASTNode *, Map *map);
    ASTVal* ASTVisit(ASTNode *, Map *map);
    ASTNode* ASTIf_stmt(ASTNode *node, Map *map);
    void ASTDef_stmt(ASTNode *node);
    void print_Result(ASTVal *v);
    bool ASTEqual(ASTNode *node, Map *map);
    ASTNode *find_def(ASTNode *node, Map *map);
    ASTVal* ASTFun_call(ASTNode *fun_exp, ASTNode *par_node);
    ASTNode* two_Node(ASTNode *exp_1, ASTNode *exp2);
    ASTNode* three_Node(ASTNode *exp_1, ASTNode *exp_2, ASTNode *exp_3);

#line 95 "file.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "file.tab.hh".  */
#ifndef YY_YY_FILE_TAB_HH_INCLUDED
# define YY_YY_FILE_TAB_HH_INCLUDED
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
    BOOL = 258,
    NUM = 259,
    ID = 260,
    MOD = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    DEFINE = 265,
    FUN = 266,
    IF = 267,
    PRINT_NUM = 268,
    PRINT_BOOL = 269
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "file.yy" /* yacc.c:355  */

    bool b;
    int num;
    char *id;
    ASTNode *node;

#line 157 "file.tab.cc" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FILE_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 172 "file.tab.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    20,    17,    15,     2,    16,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    23,    21,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    58,    62,    67,    67,    67,    68,    69,
      71,    77,    82,    88,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    98,
     100,   102,   104,   106,   108,   110,   112,   112,   112,   113,
     115,   117,   119,   121,   129,   131,   133,   135,   139,   144,
     145,   149,   154,   156,   160,   165,   175,   177,   179
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "NUM", "ID", "MOD", "AND", "OR",
  "NOT", "DEFINE", "FUN", "IF", "PRINT_NUM", "PRINT_BOOL", "'+'", "'-'",
  "'*'", "'/'", "'('", "')'", "'>'", "'<'", "'='", "$accept", "program",
  "stmts", "stmt", "print_stmt", "exps", "exp", "num_op", "plus", "minus",
  "multiply", "divid", "modulus", "greater", "smaller", "equal",
  "logical_op", "and_op", "or_op", "not_op", "def_stmt", "variable",
  "fun_exp", "fun_ids", "fun_body", "fun_call", "fun_name", "params",
  "param", "variables", "if_exp", "test_exp", "then_exp", "else_exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    43,    45,    42,    47,    40,
      41,    62,    60,    61
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,   -75,   -75,   -75,    94,     3,     5,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   115,   115,   115,
     115,    -1,   -14,   115,   115,   115,   115,   115,   115,   115,
       1,   115,   115,   115,   -75,   115,   115,   -75,   -75,     5,
      71,   115,   115,   115,    -9,   115,    -1,   115,   -75,   115,
      -6,    -4,   115,   115,   115,   115,   115,   115,   115,   -75,
      -2,   115,     2,   -75,     6,   115,   115,   -75,    11,    -1,
      20,   -75,    24,   -75,   115,   -75,   -75,   115,    28,   115,
      34,    36,    38,   115,   -75,   -75,   -75,   -75,    40,   115,
      41,   -75,   -75,   -75,   -75,   -75,    50,    52,   -75,    53,
     -75,   -75,   -75,    54,   -75,   -75,   -75,   -75,   -75,   -75,
     -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    43,     0,     0,     4,     7,     5,    15,
      20,    21,    22,    23,    24,    25,    26,    27,    16,    36,
      37,    38,     6,    14,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    51,    51,     1,     2,     4,
       0,     0,     0,     0,     0,     0,    54,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,    51,     0,     3,     0,    11,    11,    41,     0,    54,
       0,    46,     0,    57,     0,     8,     9,    11,     0,    11,
       0,     0,     0,    11,    47,    50,    48,    32,     0,    11,
       0,    42,    53,    45,    44,    58,     0,     0,    29,     0,
      31,    33,    34,     0,    39,    10,    40,    55,    28,    30,
      35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -32,    21,   -75,   -74,     0,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,    19,    -3,   -75,   -75,   -75,   -75,   -39,   -75,   -59,
     -75,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,    48,    49,     7,    98,    99,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    57,    82,    25,    46,    70,    71,    80,
      26,    59,    84,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    45,   100,    47,     3,    56,     8,    72,     1,     2,
       3,    77,    32,   107,    85,   109,    86,    73,    94,   113,
     102,     6,    96,    44,     4,   115,    97,    51,    52,    53,
      54,   101,    95,    58,    60,    61,    62,    63,    64,    65,
     103,    66,    67,    68,   104,    69,    69,    45,   108,     8,
      55,    74,    75,    76,   110,    78,   111,    81,   112,    83,
     114,   116,    87,    88,    89,    90,    91,    92,    93,    44,
     117,    69,   118,   119,   120,    79,     3,    27,    28,    29,
      30,     0,    32,    33,   105,     0,    36,    37,    38,    39,
      40,     0,    41,    42,    43,     0,     0,     0,    79,     3,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,     1,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50
};

static const yytype_int8 yycheck[] =
{
       0,     4,    76,     0,     5,    19,     6,    46,     3,     4,
       5,    20,    11,    87,    20,    89,    20,    49,    20,    93,
      79,     0,    20,     4,    19,    99,    20,    27,    28,    29,
      30,    20,    71,    33,    34,    35,    36,    37,    38,    39,
      20,    41,    42,    43,    20,    45,    46,    50,    20,    49,
      31,    51,    52,    53,    20,    55,    20,    57,    20,    59,
      20,    20,    62,    63,    64,    65,    66,    67,    68,    50,
      20,    71,    20,    20,    20,    56,     5,     6,     7,     8,
       9,    -1,    11,    12,    84,    -1,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    -1,    -1,    -1,    79,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    19,    25,    27,    28,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    49,    54,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    21,    22,    23,    45,    46,    50,     0,    26,    27,
      19,    30,    30,    30,    30,    45,    19,    47,    30,    55,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      51,    52,    51,    26,    30,    30,    30,    20,    30,    45,
      53,    30,    48,    30,    56,    20,    20,    30,    30,    30,
      30,    30,    30,    30,    20,    51,    20,    20,    29,    30,
      29,    20,    53,    20,    20,    30,    57,    29,    20,    29,
      20,    20,    20,    29,    20,    29,    20,    20,    20,    20,
      20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    26,    26,    27,    27,    27,    28,    28,
      29,    29,    30,    30,    30,    30,    30,    30,    30,    30,
      31,    31,    31,    31,    31,    31,    31,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    40,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    49,    50,
      51,    51,    52,    53,    53,    54,    55,    56,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     4,     4,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     5,
       6,     5,     5,     5,     5,     6,     1,     1,     1,     6,
       6,     4,     5,     1,     5,     3,     1,     4,     4,     1,
       2,     0,     1,     2,     0,     6,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 52 "file.yy" /* yacc.c:1646  */
    {
            operation.push(AST_ROOT);
            (yyval.node) = two_Node((yyvsp[-1].node), (yyvsp[0].node));
            root = (yyval.node);
        }
#line 1333 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "file.yy" /* yacc.c:1646  */
    {
            operation.push(AST_ROOT);
            (yyval.node) = two_Node((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1342 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "file.yy" /* yacc.c:1646  */
    { 
            operation.push(AST_NULL);
            (yyval.node) = two_Node(NULL, NULL); 
        }
#line 1351 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 68 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-1].node), NULL); }
#line 1357 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 69 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-1].node), NULL); }
#line 1363 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "file.yy" /* yacc.c:1646  */
    {
            (yyval.node) = (ASTNode *)malloc(sizeof(ASTNode));
            (yyval.node)->type = operation.top();
            (yyval.node)->lhs = (yyvsp[-1].node);
            (yyval.node)->rhs = (yyvsp[0].node);
        }
#line 1374 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 77 "file.yy" /* yacc.c:1646  */
    { 
            operation.push(AST_NULL);
            (yyval.node) = two_Node(NULL, NULL); 
        }
#line 1383 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 82 "file.yy" /* yacc.c:1646  */
    {
            ASTBool *b = (ASTBool *)malloc(sizeof(ASTBool));
            b->type = AST_BOOL;
            b->b = (yyvsp[0].b);
            (yyval.node) = (ASTNode *)b;
        }
#line 1394 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 88 "file.yy" /* yacc.c:1646  */
    {
            ASTNum *num = (ASTNum *)malloc(sizeof(ASTNum));
            num->type = AST_NUM;
            num->num = (yyvsp[0].num);
            (yyval.node) = (ASTNode *)num;
        }
#line 1405 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 96 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = three_Node((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1411 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 98 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1417 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 100 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = three_Node((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1423 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 102 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1429 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 104 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1435 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 106 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1441 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 108 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1447 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 110 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = three_Node((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1453 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 113 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = three_Node((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1459 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 115 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = three_Node((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1465 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 117 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-1].node), NULL); }
#line 1471 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 119 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1477 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 121 "file.yy" /* yacc.c:1646  */
    {
            ASTId *id = (ASTId *)malloc(sizeof(ASTId));
            id->type = AST_ID;
            id->id = (char *)malloc(sizeof(char) * strlen((yyvsp[0].id)));
            id->id = (yyvsp[0].id);
            (yyval.node) = (ASTNode *)id;
        }
#line 1489 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 129 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1495 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 131 "file.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1501 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 135 "file.yy" /* yacc.c:1646  */
    { 
                    operation.push(AST_FUN_CALL);
                    (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node));
                }
#line 1510 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 139 "file.yy" /* yacc.c:1646  */
    {
                    operation.push(AST_FUN_NAME);
                    (yyval.node) = two_Node((yyvsp[-2].node), (yyvsp[-1].node));
                }
#line 1519 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 145 "file.yy" /* yacc.c:1646  */
    {
                    operation.push(AST_NUM);
                    (yyval.node) = two_Node((yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1528 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "file.yy" /* yacc.c:1646  */
    {
                    operation.push(AST_NULL);
                    (yyval.node) = two_Node(NULL, NULL);
                }
#line 1537 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 156 "file.yy" /* yacc.c:1646  */
    {
                    operation.push(AST_ID);
                    (yyval.node) = two_Node((yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1546 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 160 "file.yy" /* yacc.c:1646  */
    { 
                    operation.push(AST_NULL);
                    (yyval.node) = two_Node(NULL, NULL); 
                }
#line 1555 "file.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 165 "file.yy" /* yacc.c:1646  */
    {
            ASTIf *if_s = (ASTIf *)malloc(sizeof(ASTIf));
            if_s->type = operation.top();
            if_s->mhs = (yyvsp[-3].node);
            if_s->lhs = (yyvsp[-2].node);
            if_s->rhs = (yyvsp[-1].node);
            (yyval.node) = (ASTNode *)if_s;
            operation.pop();
        }
#line 1569 "file.tab.cc" /* yacc.c:1646  */
    break;


#line 1573 "file.tab.cc" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 181 "file.yy" /* yacc.c:1906  */

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(0);
}

ASTNode* two_Node(ASTNode *exp_1, ASTNode *exp_2) {
    ASTNode *reduce = (ASTNode *)malloc(sizeof(ASTNode));
    reduce->type = operation.top();//use stack to get the sequential type and first in last out 
    reduce->lhs = exp_1;
    reduce->rhs = exp_2;
    operation.pop();
    return reduce;
}

ASTNode* three_Node(ASTNode *exp_1, ASTNode *exp_2, ASTNode *exp_3) {
    ASTNode *reduce = (ASTNode *)malloc(sizeof(ASTNode));
    reduce->type = operation.top();
    reduce->lhs = exp_1;
    ASTNode *rhs = (ASTNode *)malloc(sizeof(ASTNode));
    rhs->type = operation.top();
    rhs->lhs = exp_2;
    rhs->rhs = exp_3;
    reduce->rhs = rhs;
    operation.pop();
    return reduce;
}

int ASTArith(ASTNode *node, Map *map) {// here not have bool so if bool return to here will detect error
    int val;
    ASTNum *num = (ASTNum *)node;
    switch(node->type) {
        case AST_ADD:
            val = ASTArith(node->lhs, map) + ASTArith(node->rhs, map);
            if (node->rhs->type == AST_NULL) val--;// because val initail = 1
            break;
        case AST_MINUS:
            val = ASTArith(node->lhs, map) - ASTArith(node->rhs, map);
            break;
        case AST_MUL:
            val = ASTArith(node->lhs, map) * ASTArith(node->rhs, map);
            break;
        case AST_DIV:
            val = ASTArith(node->lhs, map) / ASTArith(node->rhs, map);
            break;
        case AST_MOD:
            val = ASTArith(node->lhs, map) % ASTArith(node->rhs, map);
            break;
        case AST_NUM:
            val = num->num;
            break;
        case AST_GREATER:
            if (ASTArith(node->lhs, map) > ASTArith(node->rhs, map)) val = 1;
            else val = 0;
            break;
        case AST_SMALLER:
            if (ASTArith(node->lhs, map) < ASTArith(node->rhs, map)) val = 1;
            else val = 0;
            break;
        case AST_NULL:
            val = 1;
            break;
        case AST_ID:
            val = ASTVisit(find_def(node, map), map)->num;
            break;
        default:
            // val = ASTVisit(node, map)->num;
            printf("unexpected type: %d\n", node->type); //type check %d is from enum
            puts("syntax error");
            exit(0);
            break;
    }
    return val;
}

bool ASTEqual(ASTNode *node, Map *map) {
    if (node->rhs->type != AST_NULL) {
            /* represent true and false */
        if (ASTArith(node->lhs, map) == ASTArith(node->rhs->lhs, map)) 
            return ASTEqual(node->rhs, map);
        else 
            return false;
    } else {
        return true;
    }
}

bool ASTLogical(ASTNode *node, Map *map) {// here not have num so if num return to here will detect error
    bool b;
    ASTBool *b_s = (ASTBool *)node;
    switch(node->type) {
        case AST_AND:
            b = ASTLogical(node->lhs, map) && ASTLogical(node->rhs, map);//f&f= f&(f&t)= f&(f) 
            break;
        case AST_OR:
            if (node->rhs->type == AST_NULL) {//f|f != f|(f|t) so need if just return lhs
                b = ASTLogical(node->lhs, map);
            } else {
                b = ASTLogical(node->lhs, map) || ASTLogical(node->rhs, map);
            }
            break;
        case AST_NOT:   
            b = !ASTLogical(node->lhs, map);
            break;
        case AST_GREATER:
        case AST_SMALLER:
            if (ASTArith(node, map) == 1) b = true;
            else b = false;
            break;
        case AST_EQUAL:
            b = ASTEqual(node, map);
            break;
        case AST_BOOL:            
            b = b_s->b;
            break;
        case AST_ID:
            b = ASTVisit(find_def(node, map), map)->b;
            break;
        case AST_NULL:
            b = true;
            break;
        default:
            printf("unexpected type: %d\n", node->type);
            puts("syntax error");
            exit(0);
            break;
    }
    return b;
}

ASTNode* ASTIf_stmt(ASTNode *node, Map *map) {
    ASTIf *if_s = (ASTIf *)node;
    if (ASTLogical(if_s->mhs, map)) return if_s->lhs; 
    else return if_s->rhs;
}

void ASTDef_stmt(ASTNode *node) {
    ASTId *id = (ASTId *)node->lhs;
    std::string str(id->id);//str = id->id;
    iter = def->find(str);
    if (iter != def->end()) {
        /* if found -> already defined */
        printf("Redefined id: %s\n", id->id);
        exit(0);
    } else {
        // printf("node->rhs->type: %d\n", node->rhs->type);
        // printf("define: %s\n", id->id);
        (*def)[str] = node->rhs;// Map* def;
    }
}


ASTVal* ASTFun_call(ASTNode *fun_exp, ASTNode *par_node) {
    std::vector<std::string> ids;
    std::vector<ASTNode *> params;
    ASTNode *id_node = fun_exp->lhs;// next floor 
    ASTNode *fun_body = fun_exp->rhs;
    Map* fun_map = new Map();
    if (par_node == NULL) {
        return ASTVisit(fun_body, fun_map);
    }
    if (par_node->type == AST_NULL && id_node->type == AST_NULL) {
        return ASTVisit(fun_body, fun_map);
    }
    while (par_node->type != AST_NULL) {
        ASTNode *n = (ASTNode *)ASTVisit(par_node->lhs, def);
        params.push_back(n);
        par_node = par_node->rhs;
    }
    while (id_node->type != AST_NULL) {
        ASTId *id = (ASTId *)id_node->lhs;
        std::string str(id->id);
        ids.push_back(str);
        id_node = id_node->rhs;
    }
    
    if (params.size() == ids.size()) {
        std::vector<ASTNode *>::iterator pa_it;
        std::vector<std::string>::iterator id_it;
        for (pa_it = params.begin(), id_it = ids.begin(); pa_it != params.end(); ++pa_it, ++id_it) {//fun map is local variable
            (*fun_map)[*id_it] = *pa_it;
        }
    } else {
        puts("number of params and ids do not match");
        exit(0);
    }
    /* fun_body */
    return ASTVisit(fun_body, fun_map);
}

ASTNode *find_def(ASTNode *node, Map *map) {
    ASTId *id = (ASTId *)node;
    std::string str(id->id);
    iter = map->find(str);
    if (iter == map->end()) {
        /* if found -> already defined */
        puts("variable not defined yet. in find_def");
        printf("id->id: %s\n", id->id);
        exit(0);
    }
    return iter->second;
}

ASTVal* ASTVisit(ASTNode *node, Map* map) {
    ASTVal *v = (ASTVal *)malloc(sizeof(ASTVal));
    switch(node->type) {
        case AST_ROOT://type root will right left visit
            ASTVisit(node->lhs, map);
            ASTVisit(node->rhs, map);
            break;
        case AST_ADD:
        case AST_MINUS:
        case AST_MUL:
        case AST_DIV:
        case AST_MOD:
        case AST_NUM:
            v->type = AST_NUM;
            v->num = ASTArith(node, map);
            break;
        case AST_AND:
        case AST_OR:
        case AST_NOT:        
        case AST_GREATER:
        case AST_SMALLER:
        case AST_EQUAL:
        case AST_BOOL:
            v->type = AST_BOOL;
            v->b = ASTLogical(node, map);
            break;
        case AST_ID:
            /* add find id */
            v = ASTVisit(find_def(node, map), map);
            break;
        case AST_PNUM:
            v = ASTVisit(node->lhs, map);
            printf("%d\n", v->num);
            break;
        case AST_PBOOL:
            v = ASTVisit(node->lhs, map);
            printf(v->b ? "#t\n" : "#f\n");
            break;
        case AST_IF:
            v = ASTVisit(ASTIf_stmt(node, map), map);
            // print_Result(v);
            break;
        case AST_DEF:
            ASTDef_stmt(node);
            break;
        case AST_FUN_NAME:
            v = ASTFun_call(find_def(node->lhs, map), node->rhs);
            break;
        case AST_FUN_CALL:
            v = ASTFun_call(node->lhs, node->rhs);
            break;
        case AST_FUN_EXP:
            v = ASTFun_call(node, NULL);
            break;
        case AST_NULL:
            /* do nothing */
            break;
        default:
            printf("unexpected type%d\n", node->type);
            puts("syntax error");
            exit(0);
            break;
    }
    return v;
}

/* void print_Result(ASTVal *v) {
    if (v->type == AST_NUM) {
        printf("val: %d\n", v->num);
    } else if (v->type == AST_BOOL){
        printf(v->b ? "val: #t\n" : "val: #f\n");
    } else if (v->type == AST_ID) {
        printf("val: %s\n", v->id);
    }
} */

int main(int argc, char *argv[]) {
    yyparse();
    def = new Map();
    ASTVisit(root, def);
    return(0);
}
