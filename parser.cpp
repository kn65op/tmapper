
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "gramatyka_bison.y"

	#include <string>
        #include <iostream>

        #include "KML.h"
        extern KML* tree;

        #include "textnode.h"
        #include "boolnode.h"
        #include "numbernode.h"
        #include "Document.h"
        #include "Placemark.h"
        #include "Folder.h"
        #include "Name.h"
        #include "Style.h"
        #include "Description.h"
        #include "Visibility.h"
        #include "Point.h"
        #include "LineString.h"
        #include "LinearRing.h"
        #include "Polygon.h"
        #include "Multigeometry.h"
        #include "StyleURL.h"
        #include "Coordinates.h"
	#include "OuterBoundaryIs.h"
	#include "InnerBoundaryIs.h"
	#include "IconStyle.h"
	#include "LabelStyle.h"
	#include "LineStyle.h"
	#include "PolyStyle.h"
	#include "Color.h"
	#include "Scale.h"
	#include "Heading.h"
	#include "Icon.h"
	#include "Hotspot.h"
	#include "Href.h"
	#include "Width.h"
	#include "Fill.h"
	#include "Outline.h"


        node* last_element;

	extern int yylex();
        extern int flush_lex(void);
	void yyerror(const char *s) { std::cout << "ERROR: " << s << " in line: " << flush_lex() << "\n" ;}

void makeHotspot()
{
  if (!dynamic_cast<Hotspot*>(last_element))
  {
    last_element->AddChild(new Hotspot());
    last_element = last_element->GetLastChild();
  }
}


/* Line 189 of yacc.c  */
#line 131 "parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KML_SYM = 258,
     ID_SYM = 259,
     STRING = 260,
     TEXT = 261,
     DOCUMENT_SYM = 262,
     PLACEMARK_SYM = 263,
     NAME_SYM = 264,
     STYLE_SYM = 265,
     FOLDER_SYM = 266,
     NUMBER = 267,
     DESCRIPTION_SYM = 268,
     FILL_SYM = 269,
     POINT_SYM = 270,
     MULTIGEOMETRY_SYM = 271,
     INNER_BOUNDARY_IS_SYM = 272,
     OUTER_BOUNDARY_IS_SYM = 273,
     LINE_STRING_SYM = 274,
     POLYGON_SYM = 275,
     COORDINATES_SYM = 276,
     HOTSPOT_SYM = 277,
     YUNITS_SYM = 278,
     XUNITS_SYM = 279,
     X_SYM = 280,
     Y_SYM = 281,
     ICON_SYM = 282,
     SCALE_SYM = 283,
     OUTLINE_SYM = 284,
     COLOR_SYM = 285,
     LABEL_STYLE_SYM = 286,
     STYLE_URL_SYM = 287,
     LINE_STYLE_SYM = 288,
     POLY_STYLE_SYM = 289,
     ICON_STYLE_SYM = 290,
     LINEAR_RING_SYM = 291,
     HREF_SYM = 292,
     HEADING_SYM = 293,
     VISIBILITY_SYM = 294,
     WIDTH_SYM = 295,
     TAG_OPEN = 296,
     TAG_CLOSE = 297,
     TAG_END = 298,
     COMMA = 299,
     BOOLEAN_VAL = 300,
     EQ = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 58 "gramatyka_bison.y"

		std::string *str;



/* Line 214 of yacc.c  */
#line 219 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 231 "parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNRULES -- Number of states.  */
#define YYNSTATES  403

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    12,    17,    18,    23,    28,    33,
      38,    43,    44,    49,    54,    59,    64,    69,    74,    79,
      84,    85,    90,    95,   100,   105,   110,   115,   120,   125,
     130,   135,   137,   142,   147,   151,   156,   158,   161,   167,
     172,   177,   182,   186,   191,   196,   200,   205,   210,   215,
     220,   221,   226,   231,   235,   240,   245,   249,   254,   259,
     260,   265,   270,   275,   280,   285,   290,   295,   300,   302,
     307,   312,   313,   318,   323,   328,   333,   338,   343,   344,
     349,   354,   359,   364,   367,   372,   374,   379,   384,   385,
     390,   395,   400,   402,   407,   413,   414,   419,   424,   429,
     434,   439,   444,   445,   450,   455,   460,   462,   467,   472,
     477,   478,   483,   488,   493,   495,   500,   505,   510,   511,
     516,   521,   526,   531,   533,   538,   543,   545,   550,   555,
     557,   562,   567,   572,   573,   578,   583,   588,   593,   598,
     600,   605,   610,   612,   617,   618,   623,   624
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      48,     0,    -1,    49,    51,    50,    -1,    41,     3,   140,
      42,    -1,    41,    43,     3,    42,    -1,    -1,    51,    52,
      54,    53,    -1,    51,    55,    57,    56,    -1,    51,   131,
     133,   132,    -1,    41,     7,   140,    42,    -1,    41,    43,
       7,    42,    -1,    -1,    54,    55,    57,    56,    -1,    54,
      87,    89,    88,    -1,    54,    90,    92,    91,    -1,    54,
     131,   133,   132,    -1,    54,   137,   138,   139,    -1,    54,
     134,   135,   136,    -1,    41,     8,   140,    42,    -1,    41,
      43,     8,    42,    -1,    -1,    57,    61,    62,    67,    -1,
      57,    68,    69,    70,    -1,    57,    71,    72,    73,    -1,
      57,    74,    75,    76,    -1,    57,    84,    85,    86,    -1,
      57,    58,    59,    60,    -1,    57,    87,    89,    88,    -1,
      57,   134,   135,   136,    -1,    57,   137,   138,   139,    -1,
      41,    32,   140,    42,    -1,     6,    -1,    41,    43,    32,
      42,    -1,    41,    15,   140,    42,    -1,    63,    65,    66,
      -1,    41,    21,   140,    42,    -1,    65,    -1,    64,    65,
      -1,    12,    44,    12,    44,    12,    -1,    41,    43,    21,
      42,    -1,    41,    43,    15,    42,    -1,    41,    19,   140,
      42,    -1,    63,    64,    66,    -1,    41,    43,    19,    42,
      -1,    41,    36,   140,    42,    -1,    63,    64,    66,    -1,
      41,    43,    36,    42,    -1,    41,    20,   140,    42,    -1,
      77,    78,    79,    80,    -1,    41,    43,    20,    42,    -1,
      -1,    77,    81,    82,    83,    -1,    41,    18,   140,    42,
      -1,    71,    72,    73,    -1,    41,    43,    18,    42,    -1,
      41,    17,   140,    42,    -1,    71,    72,    73,    -1,    41,
      43,    17,    42,    -1,    41,    16,   140,    42,    -1,    -1,
      85,    61,    62,    67,    -1,    85,    68,    69,    70,    -1,
      85,    71,    72,    73,    -1,    85,    74,    75,    76,    -1,
      85,    84,    85,    86,    -1,    41,    43,    16,    42,    -1,
      41,     9,   140,    42,    -1,    41,    43,     9,    42,    -1,
       6,    -1,    41,    10,   140,    42,    -1,    41,    43,    10,
      42,    -1,    -1,    92,    93,    95,    94,    -1,    92,   107,
     109,   108,    -1,    92,   113,   115,   114,    -1,    92,   119,
     121,   120,    -1,    41,    35,   140,    42,    -1,    41,    43,
      35,    42,    -1,    -1,    95,   122,   123,   124,    -1,    95,
     110,   111,   112,    -1,    95,    96,    97,    98,    -1,    95,
      99,   100,   101,    -1,    95,   105,    -1,    41,    38,   140,
      42,    -1,    12,    -1,    41,    43,    38,    42,    -1,    41,
      27,   140,    42,    -1,    -1,   100,   102,   103,   104,    -1,
      41,    43,    27,    42,    -1,    41,    37,   140,    42,    -1,
       6,    -1,    41,    43,    37,    42,    -1,    41,    22,   106,
      43,    42,    -1,    -1,   106,    25,    46,     5,    -1,   106,
      26,    46,     5,    -1,   106,    24,    46,     5,    -1,   106,
      23,    46,     5,    -1,    41,    31,   140,    42,    -1,    41,
      43,    31,    42,    -1,    -1,   109,   122,   123,   124,    -1,
     109,   110,   111,   112,    -1,    41,    28,   140,    42,    -1,
      12,    -1,    41,    43,    28,    42,    -1,    41,    33,   140,
      42,    -1,    41,    43,    33,    42,    -1,    -1,   115,   122,
     123,   124,    -1,   115,   116,   117,   118,    -1,    41,    40,
     140,    42,    -1,    12,    -1,    41,    43,    40,    42,    -1,
      41,    34,   140,    42,    -1,    41,    43,    34,    42,    -1,
      -1,   121,   122,   123,   124,    -1,   121,   125,   126,   127,
      -1,   121,   128,   129,   130,    -1,    41,    30,   140,    42,
      -1,     6,    -1,    41,    43,    30,    42,    -1,    41,    14,
     140,    42,    -1,    45,    -1,    41,    43,    14,    42,    -1,
      41,    29,   140,    42,    -1,    45,    -1,    41,    43,    29,
      42,    -1,    41,    11,   140,    42,    -1,    41,    43,    11,
      42,    -1,    -1,   133,    87,    89,    88,    -1,   133,   134,
     135,   136,    -1,   133,   137,   138,   139,    -1,   133,    55,
      57,    56,    -1,    41,    39,   140,    42,    -1,    45,    -1,
      41,    43,    39,    42,    -1,    41,    13,   140,    42,    -1,
       6,    -1,    41,    43,    13,    42,    -1,    -1,   140,   141,
      46,     5,    -1,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   115,   122,   125,   126,   127,   128,   131,
     138,   144,   145,   146,   147,   148,   149,   150,   153,   160,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     178,   185,   191,   199,   206,   209,   216,   217,   220,   229,
     232,   238,   245,   248,   254,   261,   264,   270,   277,   283,
     289,   290,   293,   300,   303,   309,   316,   319,   326,   333,
     334,   335,   336,   337,   338,   341,   347,   354,   360,   367,
     374,   380,   381,   382,   383,   384,   387,   394,   400,   401,
     402,   403,   404,   405,   408,   415,   421,   427,   434,   435,
     438,   444,   451,   457,   463,   469,   470,   475,   480,   485,
     492,   499,   505,   506,   507,   510,   517,   523,   529,   536,
     542,   543,   544,   547,   554,   560,   566,   573,   579,   580,
     581,   582,   585,   592,   598,   604,   612,   618,   624,   631,
     637,   643,   650,   656,   657,   658,   659,   660,   664,   671,
     677,   685,   692,   698,   704,   705,   708,   709
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KML_SYM", "ID_SYM", "STRING", "TEXT",
  "DOCUMENT_SYM", "PLACEMARK_SYM", "NAME_SYM", "STYLE_SYM", "FOLDER_SYM",
  "NUMBER", "DESCRIPTION_SYM", "FILL_SYM", "POINT_SYM",
  "MULTIGEOMETRY_SYM", "INNER_BOUNDARY_IS_SYM", "OUTER_BOUNDARY_IS_SYM",
  "LINE_STRING_SYM", "POLYGON_SYM", "COORDINATES_SYM", "HOTSPOT_SYM",
  "YUNITS_SYM", "XUNITS_SYM", "X_SYM", "Y_SYM", "ICON_SYM", "SCALE_SYM",
  "OUTLINE_SYM", "COLOR_SYM", "LABEL_STYLE_SYM", "STYLE_URL_SYM",
  "LINE_STYLE_SYM", "POLY_STYLE_SYM", "ICON_STYLE_SYM", "LINEAR_RING_SYM",
  "HREF_SYM", "HEADING_SYM", "VISIBILITY_SYM", "WIDTH_SYM", "TAG_OPEN",
  "TAG_CLOSE", "TAG_END", "COMMA", "BOOLEAN_VAL", "EQ", "$accept", "input",
  "kml_start", "kml_end", "kml", "document_start", "document_end",
  "document", "placemark_start", "placemark_end", "placemark",
  "style_url_start", "style_url", "style_url_end", "point_start", "point",
  "coordinates_start", "coordinates", "one_coordinates", "coordinates_end",
  "point_end", "line_string_start", "line_string", "line_string_end",
  "linear_ring_start", "linear_ring", "linear_ring_end", "polygon_start",
  "polygon", "polygon_end", "polygon_more", "outer_boundary_is_start",
  "outer_boundary_is", "outer_boundary_is_end", "inner_boundary_is_start",
  "inner_boundary_is", "inner_boundary_is_end", "multigeometry_start",
  "multigeometry", "multigeometry_end", "name_start", "name_end", "name",
  "style_start", "style_end", "style", "icon_style_start",
  "icon_style_end", "icon_style", "heading_start", "heading",
  "heading_end", "icon_start", "icon", "icon_end", "href_start", "href",
  "href_end", "hotspot", "hotspot_options", "label_style_start",
  "label_style_end", "label_style", "scale_start", "scale", "scale_end",
  "line_style_start", "line_style_end", "line_style", "width_start",
  "width", "width_end", "poly_style_start", "poly_style_end", "poly_style",
  "color_start", "color", "color_end", "fill_start", "fill", "fill_end",
  "outline_start", "outline", "outline_end", "folder_start", "folder_end",
  "folder", "visibility_start", "visibility", "visibility_end",
  "description_start", "description", "description_end", "options", "attr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    51,    51,    52,
      53,    54,    54,    54,    54,    54,    54,    54,    55,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    60,    61,    62,    63,    64,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      85,    85,    85,    85,    85,    86,    87,    88,    89,    90,
      91,    92,    92,    92,    92,    92,    93,    94,    95,    95,
      95,    95,    95,    95,    96,    97,    98,    99,   100,   100,
     101,   102,   103,   104,   105,   106,   106,   106,   106,   106,
     107,   108,   109,   109,   109,   110,   111,   112,   113,   114,
     115,   115,   115,   116,   117,   118,   119,   120,   121,   121,
     121,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   133,   133,   133,   133,   134,   135,
     136,   137,   138,   139,   140,   140,   141,   141
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     4,     0,     4,     4,     4,     4,
       4,     0,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     1,     4,     4,     3,     4,     1,     2,     5,     4,
       4,     4,     3,     4,     4,     3,     4,     4,     4,     4,
       0,     4,     4,     3,     4,     4,     3,     4,     4,     0,
       4,     4,     4,     4,     4,     4,     4,     4,     1,     4,
       4,     0,     4,     4,     4,     4,     4,     4,     0,     4,
       4,     4,     4,     2,     4,     1,     4,     4,     0,     4,
       4,     4,     1,     4,     5,     0,     4,     4,     4,     4,
       4,     4,     0,     4,     4,     4,     1,     4,     4,     4,
       0,     4,     4,     4,     1,     4,     4,     4,     0,     4,
       4,     4,     4,     1,     4,     4,     1,     4,     4,     1,
       4,     4,     4,     0,     4,     4,     4,     4,     4,     1,
       4,     4,     1,     4,     0,     4,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,   144,     1,     0,   146,     0,     2,
      11,    20,   133,   147,     3,     0,   144,   144,   144,     0,
       0,     0,     0,     0,   146,   146,   146,     0,     0,     6,
      20,     0,    71,   133,     0,     0,     0,     7,     0,     0,
       0,     0,    50,    59,     0,     0,     0,     0,    20,     0,
       8,     0,     0,   145,     9,    18,   131,     4,   144,   144,
     144,   144,     0,     0,    68,     0,     0,     0,   139,     0,
     142,     0,   144,   144,   144,   144,   144,   144,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     146,   146,   146,     0,    12,     0,    13,     0,    14,    78,
     102,   110,   118,    15,     0,    17,     0,    16,   146,   146,
     146,   146,   146,   146,     0,     0,    26,   144,     0,    21,
       0,     0,     0,    36,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,     0,     0,     0,    50,    59,
      25,    27,    28,    29,     0,   137,   134,   135,   136,    66,
      69,   141,   138,    10,     0,   144,   144,   144,   144,     0,
       0,     0,     0,     0,     0,     0,    33,    58,    41,    47,
      30,    44,    19,     0,   146,     0,     0,     0,    34,    37,
      42,     0,    45,     0,     0,   144,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
     146,   146,   146,   146,     0,     0,    72,     0,    88,    83,
       0,     0,     0,    73,     0,     0,     0,    74,     0,     0,
       0,    75,     0,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,   146,   146,     0,     0,    48,
       0,     0,    51,     0,    60,    61,    62,    63,    64,    67,
     100,   108,   116,    76,    70,    95,   144,   144,   144,   144,
       0,    85,     0,     0,   106,     0,   123,     0,     0,     0,
       0,   144,     0,   114,     0,     0,   144,   144,     0,     0,
     126,     0,   129,     0,   140,   143,    32,    40,     0,     0,
      43,    46,    49,    55,    52,    53,     0,    56,     0,    65,
       0,   146,   146,   146,   146,     0,     0,    81,     0,    82,
       0,     0,    80,     0,    79,     0,   104,   103,   146,     0,
       0,   112,   111,   146,   146,     0,   119,     0,   120,     0,
     121,    38,    39,     0,     0,     0,     0,     0,     0,     0,
      87,   105,   122,    84,    77,     0,   144,     0,    92,     0,
       0,     0,   101,   113,   109,     0,   125,   128,   117,     0,
       0,    54,    57,     0,     0,     0,     0,    94,     0,   146,
       0,     0,    89,     0,     0,     0,     0,     0,    99,    98,
      96,    97,    86,    91,    90,     0,   107,   124,   115,   127,
     130,     0,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,     6,    10,    29,    20,    48,    37,
      21,    38,    80,   126,    39,    82,    86,   132,   133,   188,
     129,    40,    85,   135,    41,    87,   138,    42,    88,   140,
      89,   142,   199,   249,   143,   201,   252,    43,    90,   150,
      44,   106,    65,    32,   108,    66,   109,   216,   170,   217,
     272,   317,   218,   273,   319,   320,   359,   382,   219,   310,
     110,   223,   171,   220,   275,   322,   111,   227,   172,   228,
     284,   331,   112,   231,   173,   221,   277,   324,   233,   291,
     338,   234,   293,   340,    12,    50,    22,    45,    69,   115,
      46,    71,   117,     7,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -197
static const yytype_int16 yypact[] =
{
     -23,    17,    82,  -197,  -197,  -197,   103,     7,    96,  -197,
    -197,  -197,  -197,  -197,  -197,    70,  -197,  -197,  -197,    86,
     105,   115,   127,   124,     8,    13,    29,   161,   132,  -197,
    -197,   170,  -197,  -197,   150,   207,   146,  -197,   208,   176,
     176,   176,  -197,  -197,   170,   150,   207,   145,  -197,   170,
    -197,   150,   207,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,   209,   115,  -197,   180,   182,   127,  -197,   183,
    -197,   184,  -197,  -197,  -197,  -197,  -197,  -197,   218,  -197,
     186,   210,   187,   217,   217,   189,   217,   191,   192,   193,
     194,   180,   183,   184,   225,   115,   180,   183,   184,    30,
      31,    32,    33,   195,  -197,   196,  -197,   177,  -197,  -197,
    -197,  -197,  -197,  -197,   197,  -197,   198,  -197,    34,    35,
      36,    37,    42,    43,   200,   201,  -197,  -197,   202,  -197,
     199,   205,    97,  -197,   204,  -197,    97,   206,  -197,   211,
    -197,   188,   214,   214,   154,   176,   176,   176,  -197,  -197,
    -197,  -197,  -197,  -197,   215,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,   229,  -197,  -197,  -197,  -197,   238,
     219,   220,   221,   222,   227,   243,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,   226,    44,   244,   252,   224,  -197,  -197,
    -197,   249,  -197,   233,   253,  -197,  -197,   236,   176,   234,
     176,   235,   258,   187,   189,   191,   192,   194,  -197,   237,
      48,    49,    76,    77,   239,   164,  -197,   265,  -197,  -197,
     266,   274,   153,  -197,   266,   274,   117,  -197,   270,   274,
     134,  -197,   274,   240,   241,   242,   245,   246,  -197,   247,
     248,   262,   251,   254,   255,    83,    84,   191,   256,  -197,
     191,   257,  -197,   259,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
     260,  -197,   250,   261,  -197,   263,  -197,   264,   267,   263,
     264,  -197,   273,  -197,   268,   264,  -197,  -197,   269,   264,
    -197,   271,  -197,   272,  -197,  -197,  -197,  -197,   278,   275,
    -197,  -197,  -197,  -197,  -197,  -197,   276,  -197,   290,  -197,
     175,    88,    89,    90,    91,   277,   279,  -197,   -11,  -197,
     302,   280,  -197,   281,  -197,   283,  -197,  -197,    92,   284,
     285,  -197,  -197,    93,    94,   287,  -197,   288,  -197,   289,
    -197,  -197,  -197,   291,   292,   293,   295,   296,   297,   294,
    -197,  -197,  -197,  -197,  -197,   282,  -197,   300,  -197,   303,
     286,   305,  -197,  -197,  -197,   298,  -197,  -197,  -197,   301,
     308,  -197,  -197,   306,   311,   313,   316,  -197,   304,    95,
     307,   309,  -197,   312,   314,   315,   317,   318,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,   310,  -197,  -197,  -197,  -197,
    -197,   319,  -197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,    10,    20,
     -17,  -197,  -197,  -197,   -87,   165,   -32,   299,   -68,    -8,
     142,   -86,   212,   126,   -80,  -133,  -196,   -85,   203,   144,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,   -84,   213,   148,
      -1,     9,    68,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,   216,   129,    69,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -144,   -10,  -179,  -197,  -197,
    -197,  -197,  -197,  -197,   343,   321,   331,     2,    57,    75,
       3,   141,   111,   -16,  -197
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      24,    25,    26,   145,   146,   148,   149,    83,    84,   256,
     147,    13,    13,    63,   205,   131,    11,    13,     1,    31,
       4,    49,    34,    35,    51,    52,   356,   225,   229,   232,
      30,    95,   357,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    99,   100,   101,   102,    13,    13,    13,    14,
      54,   305,    13,    13,   307,    55,   118,   119,   120,   121,
     122,   123,   198,   200,   189,   247,    49,   250,   189,    51,
      52,    56,   159,   160,   161,   162,   176,   177,   178,   179,
      13,    13,     5,   104,   180,   181,   238,    13,    13,    27,
     260,   261,    13,    13,    13,    13,    13,    13,    13,    13,
     151,   327,    92,    16,    17,   156,   332,    18,    97,   130,
     336,   184,    91,    83,    84,   155,    23,    96,   262,   263,
     145,   146,   148,   149,   190,   303,   304,   147,   192,    53,
     350,   351,   352,   353,   363,   366,   367,   393,   187,    19,
      17,    58,    59,    18,     8,    60,    28,   268,   286,   210,
     211,   212,   213,    17,    58,    58,    36,   281,    60,    60,
     282,    72,    73,   287,   268,    74,    75,   152,    47,    72,
      73,    61,   157,    74,    75,    62,    64,   288,    76,   245,
     246,   267,    77,   268,    61,    61,   265,    93,    94,    78,
      77,   266,   267,    98,   268,    68,   278,   202,   345,   346,
     347,   348,   269,    57,   153,   195,   196,   270,   165,   158,
     166,   167,   168,    70,    79,   280,   103,    81,   349,   285,
     169,   105,   289,   107,   114,   116,   124,   125,   128,   130,
     134,   127,   137,   139,   141,   144,   154,   163,   209,   164,
     174,   175,   182,   186,   183,   185,   187,   191,   214,   193,
     311,   312,   313,   314,   194,   197,   236,   208,   237,   239,
     215,   222,   226,   230,   240,   328,   235,   241,   242,   243,
     333,   334,    77,   244,   253,   248,   251,   271,   274,   259,
     276,   264,   283,   299,   294,   290,   292,   295,   296,   297,
     341,   316,   298,   300,   343,   315,   301,   302,   325,   306,
     308,   309,   318,   335,   321,   323,   329,   344,   358,   330,
     203,   388,   337,   339,   383,   386,   389,   342,   390,   354,
     378,   391,   355,   360,   361,   362,   364,   380,   365,   368,
     255,   369,   370,   371,   372,   384,   377,   387,   385,   373,
     379,   374,   375,   376,   381,   254,   392,   401,   326,   394,
     257,   206,   395,   279,   396,   258,   397,   398,   204,   399,
     400,   402,   207,    33,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,     0,   224,   113
};

static const yytype_int16 yycheck[] =
{
      16,    17,    18,    90,    90,    90,    90,    39,    40,   205,
      90,     4,     4,    30,   147,    83,     6,     4,    41,    20,
       3,    22,    20,    20,    22,    22,    37,   171,   172,   173,
      20,    48,    43,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    58,    59,    60,    61,     4,     4,     4,    42,
      42,   247,     4,     4,   250,    42,    72,    73,    74,    75,
      76,    77,   142,   143,   132,   198,    67,   200,   136,    67,
      67,    42,    42,    42,    42,    42,    42,    42,    42,    42,
       4,     4,     0,    63,    42,    42,    42,     4,     4,     3,
      42,    42,     4,     4,     4,     4,     4,     4,     4,     4,
      91,   280,    45,     7,     8,    96,   285,    11,    51,    12,
     289,   127,    44,   145,   146,    95,    46,    49,    42,    42,
     207,   207,   207,   207,   132,    42,    42,   207,   136,     5,
      42,    42,    42,    42,    42,    42,    42,    42,    41,    43,
       8,     9,    10,    11,    41,    13,    41,    30,    14,   165,
     166,   167,   168,     8,     9,     9,    41,    40,    13,    13,
      43,    15,    16,    29,    30,    19,    20,    92,    41,    15,
      16,    39,    97,    19,    20,    43,     6,    43,    32,   195,
     196,    28,    36,    30,    39,    39,    22,    46,    43,    43,
      36,    27,    28,    52,    30,    45,    43,    43,    23,    24,
      25,    26,    38,    42,    93,    17,    18,    43,    31,    98,
      33,    34,    35,     6,     6,   225,     7,    41,    43,   229,
      43,    41,   232,    41,    41,    41,     8,    41,    41,    12,
      41,    21,    41,    41,    41,    41,    11,    42,     9,    43,
      43,    43,    42,    44,    43,    43,    41,    43,    10,    43,
     266,   267,   268,   269,    43,    41,    13,    42,    32,    15,
      41,    41,    41,    41,    12,   281,    39,    43,    19,    36,
     286,   287,    36,    20,    16,    41,    41,    12,    12,    42,
       6,    42,    12,    21,    42,    45,    45,    42,    42,    42,
      12,    41,    44,    42,    18,    35,    42,    42,    31,    43,
      43,    42,    41,    34,    41,    41,    33,    17,     6,    41,
     145,     5,    41,    41,    28,    14,     5,    42,     5,    42,
      38,     5,    43,    43,    43,    42,    42,    27,    43,    42,
     204,    43,    43,    42,    42,    30,    42,    29,    40,    46,
     356,    46,    46,    46,    41,   203,    42,    37,   279,    42,
     206,   148,    43,   224,    42,   207,    42,    42,   146,    42,
      42,    42,   149,    20,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,   171,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    48,    49,     3,     0,    51,   140,    41,    50,
      52,    55,   131,     4,    42,   141,     7,     8,    11,    43,
      54,    57,   133,    46,   140,   140,   140,     3,    41,    53,
      55,    87,    90,   131,   134,   137,    41,    56,    58,    61,
      68,    71,    74,    84,    87,   134,   137,    41,    55,    87,
     132,   134,   137,     5,    42,    42,    42,    42,     9,    10,
      13,    39,    43,    57,     6,    89,    92,   133,    45,   135,
       6,   138,    15,    16,    19,    20,    32,    36,    43,     6,
      59,    41,    62,    63,    63,    69,    63,    72,    75,    77,
      85,    89,   135,   138,    43,    57,    89,   135,   138,   140,
     140,   140,   140,     7,    56,    41,    88,    41,    91,    93,
     107,   113,   119,   132,    41,   136,    41,   139,   140,   140,
     140,   140,   140,   140,     8,    41,    60,    21,    41,    67,
      12,    65,    64,    65,    41,    70,    64,    41,    73,    41,
      76,    41,    78,    81,    41,    61,    68,    71,    74,    84,
      86,    88,   136,   139,    11,    56,    88,   136,   139,    42,
      42,    42,    42,    42,    43,    31,    33,    34,    35,    43,
      95,   109,   115,   121,    43,    43,    42,    42,    42,    42,
      42,    42,    42,    43,   140,    43,    44,    41,    66,    65,
      66,    43,    66,    43,    43,    17,    18,    41,    71,    79,
      71,    82,    43,    62,    69,    72,    75,    85,    42,     9,
     140,   140,   140,   140,    10,    41,    94,    96,    99,   105,
     110,   122,    41,   108,   110,   122,    41,   114,   116,   122,
      41,   120,   122,   125,   128,    39,    13,    32,    42,    15,
      12,    43,    19,    36,    20,   140,   140,    72,    41,    80,
      72,    41,    83,    16,    67,    70,    73,    76,    86,    42,
      42,    42,    42,    42,    42,    22,    27,    28,    30,    38,
      43,    12,    97,   100,    12,   111,     6,   123,    43,   111,
     123,    40,    43,    12,   117,   123,    14,    29,    43,   123,
      45,   126,    45,   129,    42,    42,    42,    42,    44,    21,
      42,    42,    42,    42,    42,    73,    43,    73,    43,    42,
     106,   140,   140,   140,   140,    35,    41,    98,    41,   101,
     102,    41,   112,    41,   124,    31,   112,   124,   140,    33,
      41,   118,   124,   140,   140,    34,   124,    41,   127,    41,
     130,    12,    42,    18,    17,    23,    24,    25,    26,    43,
      42,    42,    42,    42,    42,    43,    37,    43,     6,   103,
      43,    43,    42,    42,    42,    43,    42,    42,    42,    43,
      43,    42,    42,    46,    46,    46,    46,    42,    38,   140,
      27,    41,   104,    28,    30,    40,    14,    29,     5,     5,
       5,     5,    42,    42,    42,    43,    42,    42,    42,    42,
      42,    37,    42
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 116 "gramatyka_bison.y"
    {
  tree = new KML((yyvsp[(3) - (4)].str));
  last_element = tree
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 132 "gramatyka_bison.y"
    {
last_element->AddChild(new Document((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 139 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 154 "gramatyka_bison.y"
    {
last_element->AddChild(new Placemark((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 161 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 179 "gramatyka_bison.y"
    {
last_element->AddChild(new StyleURL((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 186 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 192 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 200 "gramatyka_bison.y"
    {
last_element->AddChild(new Point((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 210 "gramatyka_bison.y"
    {
last_element->AddChild(new Coordinates((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 221 "gramatyka_bison.y"
    {
if (dynamic_cast<Coordinates*>(last_element))
{
  dynamic_cast<Coordinates*>(last_element)->addCoordinate((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str));
}
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 233 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 239 "gramatyka_bison.y"
    {
last_element->AddChild(new LineString((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 249 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 255 "gramatyka_bison.y"
    {
last_element->AddChild(new LinearRing((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 265 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 271 "gramatyka_bison.y"
    {
last_element->AddChild(new Polygon((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 284 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 294 "gramatyka_bison.y"
    {
last_element->AddChild(new OuterBoundaryIs((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 304 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 310 "gramatyka_bison.y"
    {
last_element->AddChild(new InnerBoundaryIs((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 320 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 327 "gramatyka_bison.y"
    {
last_element->AddChild(new Multigeometry((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 342 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 348 "gramatyka_bison.y"
    {
last_element->AddChild(new Name((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 355 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 361 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 368 "gramatyka_bison.y"
    {
last_element->AddChild(new Style((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 375 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 388 "gramatyka_bison.y"
    {
last_element->AddChild(new IconStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 395 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 409 "gramatyka_bison.y"
    {
last_element->AddChild(new Heading((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 416 "gramatyka_bison.y"
    {
last_element->AddChild(new numbernode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 422 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 428 "gramatyka_bison.y"
    {
last_element->AddChild(new Icon((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 439 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 445 "gramatyka_bison.y"
    {
last_element->AddChild(new Href((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 452 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 458 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 464 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 471 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setX((yyvsp[(4) - (4)].str));
;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 476 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setY((yyvsp[(4) - (4)].str));
;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 481 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setXunits((yyvsp[(4) - (4)].str));
;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 486 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setYunits((yyvsp[(4) - (4)].str));
;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 493 "gramatyka_bison.y"
    {
last_element->AddChild(new LabelStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 500 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 511 "gramatyka_bison.y"
    {
last_element->AddChild(new Scale((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 518 "gramatyka_bison.y"
    {
last_element->AddChild(new numbernode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 524 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 530 "gramatyka_bison.y"
    {
last_element->AddChild(new LineStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 537 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 548 "gramatyka_bison.y"
    {
last_element->AddChild(new Width((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 555 "gramatyka_bison.y"
    {
last_element->AddChild(new numbernode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 561 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 567 "gramatyka_bison.y"
    {
last_element->AddChild(new PolyStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 574 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 586 "gramatyka_bison.y"
    {
last_element->AddChild(new Color((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 593 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 599 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 605 "gramatyka_bison.y"
    {
last_element->AddChild(new Fill((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 613 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 619 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 625 "gramatyka_bison.y"
    {
last_element->AddChild(new Outline((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 632 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 638 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 644 "gramatyka_bison.y"
    {
last_element->AddChild(new Folder((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 651 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 665 "gramatyka_bison.y"
    {
last_element->AddChild(new Visibility((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 672 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 678 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 686 "gramatyka_bison.y"
    {
last_element->AddChild(new Description((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 693 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 699 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 704 "gramatyka_bison.y"
    {(yyval.str) = NULL;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 705 "gramatyka_bison.y"
    {(yyval.str) = (yyvsp[(4) - (4)].str);}
    break;



/* Line 1455 of yacc.c  */
#line 2485 "parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



