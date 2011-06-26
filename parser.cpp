
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
        #include "MainWindow.h"

        extern KML* tree;
        extern MainWindow *gui;

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
        extern void restart(void);
	void yyerror(const char *s) { MainWindow::showError(s, flush_lex(), gui);/*std::cout << "ERROR: " << s << " in line: " << flush_lex() << "\n" ;*/}

void makeHotspot()
{
  if (!dynamic_cast<Hotspot*>(last_element))
  {
    last_element->AddChild(new Hotspot());
    last_element = last_element->GetLastChild();
  }
}


/* Line 189 of yacc.c  */
#line 135 "parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     VISIBILITY_SYM = 293,
     WIDTH_SYM = 294,
     TAG_OPEN = 295,
     TAG_CLOSE = 296,
     TAG_END = 297,
     COMMA = 298,
     BOOLEAN_VAL = 299,
     EQ = 300,
     SYM_NOT_VALID = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 64 "gramatyka_bison.y"

		std::string *str;



/* Line 214 of yacc.c  */
#line 223 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 235 "parser.cpp"

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
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNRULES -- Number of states.  */
#define YYNSTATES  392

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
     349,   354,   357,   362,   363,   368,   373,   378,   380,   385,
     391,   392,   397,   402,   407,   412,   417,   422,   423,   428,
     433,   438,   440,   445,   450,   455,   456,   461,   466,   471,
     473,   478,   483,   488,   489,   494,   499,   504,   509,   511,
     516,   521,   523,   528,   533,   535,   540,   545,   550,   551,
     556,   561,   566,   571,   576,   581,   583,   588,   593,   595,
     600,   601,   606,   607
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      48,     0,    -1,    49,    51,    50,    -1,    40,     3,   137,
      41,    -1,    40,    42,     3,    41,    -1,    -1,    51,    52,
      54,    53,    -1,    51,    55,    57,    56,    -1,    51,   128,
     130,   129,    -1,    40,     7,   137,    41,    -1,    40,    42,
       7,    41,    -1,    -1,    54,    55,    57,    56,    -1,    54,
      87,    89,    88,    -1,    54,    90,    92,    91,    -1,    54,
     128,   130,   129,    -1,    54,   134,   135,   136,    -1,    54,
     131,   132,   133,    -1,    40,     8,   137,    41,    -1,    40,
      42,     8,    41,    -1,    -1,    57,    61,    62,    67,    -1,
      57,    68,    69,    70,    -1,    57,    71,    72,    73,    -1,
      57,    74,    75,    76,    -1,    57,    84,    85,    86,    -1,
      57,    58,    59,    60,    -1,    57,    87,    89,    88,    -1,
      57,   131,   132,   133,    -1,    57,   134,   135,   136,    -1,
      40,    32,   137,    41,    -1,     6,    -1,    40,    42,    32,
      41,    -1,    40,    15,   137,    41,    -1,    63,    65,    66,
      -1,    40,    21,   137,    41,    -1,    65,    -1,    64,    65,
      -1,    12,    43,    12,    43,    12,    -1,    40,    42,    21,
      41,    -1,    40,    42,    15,    41,    -1,    40,    19,   137,
      41,    -1,    63,    64,    66,    -1,    40,    42,    19,    41,
      -1,    40,    36,   137,    41,    -1,    63,    64,    66,    -1,
      40,    42,    36,    41,    -1,    40,    20,   137,    41,    -1,
      77,    78,    79,    80,    -1,    40,    42,    20,    41,    -1,
      -1,    77,    81,    82,    83,    -1,    40,    18,   137,    41,
      -1,    71,    72,    73,    -1,    40,    42,    18,    41,    -1,
      40,    17,   137,    41,    -1,    71,    72,    73,    -1,    40,
      42,    17,    41,    -1,    40,    16,   137,    41,    -1,    -1,
      85,    61,    62,    67,    -1,    85,    68,    69,    70,    -1,
      85,    71,    72,    73,    -1,    85,    74,    75,    76,    -1,
      85,    84,    85,    86,    -1,    40,    42,    16,    41,    -1,
      40,     9,   137,    41,    -1,    40,    42,     9,    41,    -1,
       6,    -1,    40,    10,   137,    41,    -1,    40,    42,    10,
      41,    -1,    -1,    92,    93,    95,    94,    -1,    92,   104,
     106,   105,    -1,    92,   110,   112,   111,    -1,    92,   116,
     118,   117,    -1,    40,    35,   137,    41,    -1,    40,    42,
      35,    41,    -1,    -1,    95,   119,   120,   121,    -1,    95,
      96,    97,    98,    -1,    95,   102,    -1,    40,    27,   137,
      41,    -1,    -1,    97,    99,   100,   101,    -1,    40,    42,
      27,    41,    -1,    40,    37,   137,    41,    -1,     6,    -1,
      40,    42,    37,    41,    -1,    40,    22,   103,    42,    41,
      -1,    -1,   103,    25,    45,     5,    -1,   103,    26,    45,
       5,    -1,   103,    24,    45,     5,    -1,   103,    23,    45,
       5,    -1,    40,    31,   137,    41,    -1,    40,    42,    31,
      41,    -1,    -1,   106,   119,   120,   121,    -1,   106,   107,
     108,   109,    -1,    40,    28,   137,    41,    -1,    12,    -1,
      40,    42,    28,    41,    -1,    40,    33,   137,    41,    -1,
      40,    42,    33,    41,    -1,    -1,   112,   119,   120,   121,
      -1,   112,   113,   114,   115,    -1,    40,    39,   137,    41,
      -1,    12,    -1,    40,    42,    39,    41,    -1,    40,    34,
     137,    41,    -1,    40,    42,    34,    41,    -1,    -1,   118,
     119,   120,   121,    -1,   118,   122,   123,   124,    -1,   118,
     125,   126,   127,    -1,    40,    30,   137,    41,    -1,     6,
      -1,    40,    42,    30,    41,    -1,    40,    14,   137,    41,
      -1,    44,    -1,    40,    42,    14,    41,    -1,    40,    29,
     137,    41,    -1,    44,    -1,    40,    42,    29,    41,    -1,
      40,    11,   137,    41,    -1,    40,    42,    11,    41,    -1,
      -1,   130,    87,    89,    88,    -1,   130,   128,   130,   129,
      -1,   130,   131,   132,   133,    -1,   130,   134,   135,   136,
      -1,   130,    55,    57,    56,    -1,    40,    38,   137,    41,
      -1,    44,    -1,    40,    42,    38,    41,    -1,    40,    13,
     137,    41,    -1,     6,    -1,    40,    42,    13,    41,    -1,
      -1,   137,   138,    45,     5,    -1,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   121,   133,   136,   137,   138,   139,   142,
     149,   155,   156,   157,   158,   159,   160,   161,   164,   171,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     189,   196,   202,   210,   217,   220,   227,   228,   231,   240,
     246,   252,   259,   262,   268,   275,   278,   284,   291,   297,
     303,   304,   307,   314,   317,   323,   330,   333,   340,   347,
     348,   349,   350,   351,   352,   355,   361,   368,   374,   381,
     388,   394,   395,   396,   397,   398,   401,   408,   414,   415,
     416,   417,   420,   427,   428,   431,   437,   444,   450,   456,
     462,   463,   468,   473,   478,   485,   492,   498,   499,   500,
     503,   510,   516,   522,   529,   535,   536,   537,   540,   547,
     553,   559,   566,   572,   573,   574,   575,   578,   585,   591,
     597,   605,   611,   617,   624,   630,   636,   643,   649,   650,
     651,   652,   653,   654,   658,   665,   671,   679,   686,   692,
     698,   699,   702,   703
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
  "HREF_SYM", "VISIBILITY_SYM", "WIDTH_SYM", "TAG_OPEN", "TAG_CLOSE",
  "TAG_END", "COMMA", "BOOLEAN_VAL", "EQ", "SYM_NOT_VALID", "$accept",
  "input", "kml_start", "kml_end", "kml", "document_start", "document_end",
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
  "icon_style_end", "icon_style", "icon_start", "icon", "icon_end",
  "href_start", "href", "href_end", "hotspot", "hotspot_options",
  "label_style_start", "label_style_end", "label_style", "scale_start",
  "scale", "scale_end", "line_style_start", "line_style_end", "line_style",
  "width_start", "width", "width_end", "poly_style_start",
  "poly_style_end", "poly_style", "color_start", "color", "color_end",
  "fill_start", "fill", "fill_end", "outline_start", "outline",
  "outline_end", "folder_start", "folder_end", "folder",
  "visibility_start", "visibility", "visibility_end", "description_start",
  "description", "description_end", "options", "attr", 0
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
      95,    95,    96,    97,    97,    98,    99,   100,   101,   102,
     103,   103,   103,   103,   103,   104,   105,   106,   106,   106,
     107,   108,   109,   110,   111,   112,   112,   112,   113,   114,
     115,   116,   117,   118,   118,   118,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   130,
     130,   130,   130,   130,   131,   132,   133,   134,   135,   136,
     137,   137,   138,   138
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
       4,     2,     4,     0,     4,     4,     4,     1,     4,     5,
       0,     4,     4,     4,     4,     4,     4,     0,     4,     4,
       4,     1,     4,     4,     4,     0,     4,     4,     4,     1,
       4,     4,     4,     0,     4,     4,     4,     4,     1,     4,
       4,     1,     4,     4,     1,     4,     4,     4,     0,     4,
       4,     4,     4,     4,     4,     1,     4,     4,     1,     4,
       0,     4,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,   140,     1,     0,   142,     0,     2,
      11,    20,   128,   143,     3,     0,   140,   140,   140,     0,
       0,     0,     0,     0,   142,   142,   142,     0,     0,     6,
      20,     0,    71,   128,     0,     0,     0,     7,     0,     0,
       0,     0,    50,    59,     0,     0,     0,     0,    20,     0,
     128,     8,     0,     0,   141,     9,    18,   126,     4,   140,
     140,   140,   140,     0,     0,    68,     0,     0,     0,   135,
       0,   138,     0,   140,   140,   140,   140,   140,   140,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   142,   142,   142,     0,    12,     0,    13,     0,
      14,    78,    97,   105,   113,    15,     0,    17,     0,    16,
     142,   142,   142,   142,   142,   142,     0,     0,    26,   140,
       0,    21,     0,     0,     0,    36,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,     0,     0,     0,
      50,    59,    25,    27,    28,    29,     0,   133,   129,   130,
     131,   132,    66,    69,   137,   134,    10,     0,   140,   140,
     140,   140,     0,     0,     0,     0,     0,     0,     0,    33,
      58,    41,    47,    30,    44,    19,     0,   142,     0,     0,
       0,    34,    37,    42,     0,    45,     0,     0,   140,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,   142,   142,   142,   142,     0,     0,    72,
      83,    81,     0,     0,    73,     0,     0,     0,    74,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,   142,   142,     0,     0,
      48,     0,     0,    51,     0,    60,    61,    62,    63,    64,
      67,    95,   103,   111,    76,    70,    90,   140,   140,     0,
       0,   118,     0,   140,     0,   101,     0,     0,   140,     0,
     109,     0,     0,   140,   140,     0,     0,   121,     0,   124,
       0,   136,   139,    32,    40,     0,     0,    43,    46,    49,
      55,    52,    53,     0,    56,     0,    65,     0,   142,   142,
       0,     0,    80,     0,     0,    79,   142,     0,     0,    99,
      98,   142,     0,     0,   107,   106,   142,   142,     0,   114,
       0,   115,     0,   116,    38,    39,     0,     0,     0,     0,
       0,     0,     0,    82,   117,    77,   140,     0,    87,     0,
       0,   100,    96,     0,   108,   104,     0,   120,   123,   112,
       0,     0,    54,    57,     0,     0,     0,     0,    89,   142,
       0,     0,    84,     0,     0,     0,     0,     0,    94,    93,
      91,    92,    86,    85,     0,   119,   102,   110,   122,   125,
       0,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,     6,    10,    29,    20,    48,    37,
      21,    38,    81,   128,    39,    83,    87,   134,   135,   191,
     131,    40,    86,   137,    41,    88,   140,    42,    89,   142,
      90,   144,   202,   250,   145,   204,   253,    43,    91,   152,
      44,   108,    66,    32,   110,    67,   111,   219,   173,   220,
     270,   312,   313,   349,   372,   221,   307,   112,   224,   174,
     225,   276,   319,   113,   228,   175,   229,   281,   324,   114,
     232,   176,   222,   272,   315,   234,   288,   331,   235,   290,
     333,    50,    51,    22,    45,    70,   117,    46,    72,   119,
       7,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -200
static const yytype_int16 yypact[] =
{
      47,    82,    88,  -200,  -200,  -200,   101,     7,   100,  -200,
    -200,  -200,  -200,  -200,  -200,   104,  -200,  -200,  -200,   147,
     136,   182,   183,   155,     9,    10,    26,   126,   135,  -200,
    -200,   208,  -200,  -200,   145,   218,   149,  -200,   219,   186,
     186,   186,  -200,  -200,   208,   145,   218,   119,  -200,   208,
    -200,  -200,   145,   218,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,   220,   182,  -200,   188,   189,   183,  -200,
     190,  -200,   191,  -200,  -200,  -200,  -200,  -200,  -200,   224,
    -200,   193,   213,   195,   225,   225,   196,   225,   198,   199,
     200,   201,   188,   190,   191,   231,   182,   188,   183,   190,
     191,    30,    32,    33,    34,   202,  -200,   203,  -200,    -7,
    -200,  -200,  -200,  -200,  -200,  -200,   204,  -200,   205,  -200,
      36,    37,    38,    43,    49,    50,   207,   211,  -200,  -200,
     212,  -200,   206,   210,    74,  -200,   214,  -200,    74,   216,
    -200,   217,  -200,    14,   215,   215,   159,   186,   186,   186,
    -200,  -200,  -200,  -200,  -200,  -200,   222,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,   235,  -200,  -200,
    -200,  -200,   250,   221,   226,   229,   230,   227,   251,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,   239,    51,   257,   261,
     232,  -200,  -200,  -200,   256,  -200,   240,   258,  -200,  -200,
     241,   186,   242,   186,   243,   263,   195,   196,   198,   199,
     201,  -200,   244,    52,    76,    77,    78,   245,   166,  -200,
    -200,  -200,   274,   162,  -200,   269,   274,   164,  -200,   272,
     274,   142,  -200,   274,   246,   247,   248,   252,   253,  -200,
     254,   249,   266,   255,   259,   260,    79,    85,   198,   262,
    -200,   198,   264,  -200,   267,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,   268,
     265,  -200,   270,  -200,   271,  -200,   273,   270,  -200,   276,
    -200,   275,   270,  -200,  -200,   277,   270,  -200,   278,  -200,
     279,  -200,  -200,  -200,  -200,   285,   280,  -200,  -200,  -200,
    -200,  -200,  -200,   281,  -200,   290,  -200,   174,    90,    93,
     282,   168,  -200,   292,   283,  -200,    94,   286,   284,  -200,
    -200,    96,   287,   289,  -200,  -200,    97,    98,   288,  -200,
     291,  -200,   293,  -200,  -200,  -200,   295,   296,   294,   297,
     298,   299,   300,  -200,  -200,  -200,  -200,   305,  -200,   306,
     304,  -200,  -200,   310,  -200,  -200,   301,  -200,  -200,  -200,
     302,   316,  -200,  -200,   307,   309,   312,   315,  -200,    99,
     308,   311,  -200,   313,   314,   317,   318,   319,  -200,  -200,
    -200,  -200,  -200,  -200,   320,  -200,  -200,  -200,  -200,  -200,
     321,  -200
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,    19,    40,
     -15,  -200,  -200,  -200,   -88,   141,   -32,   237,   -62,   -28,
     116,   -87,   223,   140,   -81,  -133,  -199,   -86,   228,   139,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,   -85,   233,   146,
      -3,   120,   169,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,    45,  -121,   -75,  -200,  -200,  -200,  -200,  -200,
    -200,   127,    53,   -21,    -2,   114,    87,     1,   117,   115,
     -16,  -200
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      24,    25,    26,   147,   148,   150,   151,    84,    85,   257,
     149,    13,    68,    13,    13,    64,   208,    31,    34,    49,
      52,    35,   133,    53,   168,    11,   169,   170,   171,    98,
      13,   198,   199,    96,    13,   172,    13,    13,    13,    30,
      13,    13,    13,   101,   102,   103,   104,    13,    14,   302,
      55,    56,   304,    13,    13,    13,    13,   120,   121,   122,
     123,   124,   125,   201,   203,    49,    52,    57,   248,    53,
     251,   162,   192,   163,   164,   165,   192,   179,   180,   181,
      13,    13,    13,    13,   182,     4,   132,     1,     5,    13,
     183,   184,   239,   261,    13,    49,    52,    13,    13,    53,
      13,    13,    13,    13,   106,   277,   193,    16,    17,   282,
     195,    18,   286,   187,   190,    84,    85,   262,   263,   264,
     300,   115,   147,   148,   150,   151,   301,    17,    59,   149,
      18,   343,    61,    12,   344,   351,   157,   354,   357,   358,
     382,     8,    19,    17,    59,    60,    18,    33,    61,    23,
      27,   159,   213,   214,   215,   216,   283,    62,    59,    93,
      54,    95,    61,    94,    73,    74,    99,    58,    75,    76,
     100,   284,   268,    62,    73,    74,    28,    63,    75,    76,
     154,    77,   246,   247,   285,    78,   160,    62,   266,    69,
     273,    79,   268,   267,   268,    78,   268,   338,   339,   340,
     341,   205,   320,   278,   274,   346,   279,   325,   269,   155,
     347,   329,   153,    92,    65,   161,   342,   158,    97,   226,
     230,   233,    36,    47,    71,    80,    82,   105,   107,   109,
     116,   118,   126,   127,   129,   130,   136,   132,   139,   141,
     143,   146,   156,   166,   212,   167,   177,   178,   185,   189,
     190,   308,   309,   186,   188,   200,   194,   316,   196,   197,
     217,   218,   321,   211,   237,   236,   223,   326,   327,   227,
     231,   238,   240,   241,   242,   243,   244,    78,   245,   254,
     271,   275,   249,   252,   280,   260,   265,   296,   206,   291,
     287,   289,   295,   292,   293,   294,   297,   334,   348,   336,
     298,   299,   317,   310,   303,   311,   305,   337,   306,   322,
     314,   328,   378,   318,   379,   323,   376,   380,   330,   332,
     381,   335,   255,   345,   138,   350,   353,   352,   355,   359,
     369,   356,   370,   360,   373,   361,   362,   363,   374,   364,
     375,   368,   365,   366,   367,   377,   371,   256,   258,   383,
       0,     0,     0,   384,   385,   386,   259,   390,   387,   388,
     389,     0,   391,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,     0,     0,   209,     0,
       0,     0,     0,     0,   210
};

static const yytype_int16 yycheck[] =
{
      16,    17,    18,    91,    91,    91,    91,    39,    40,   208,
      91,     4,    33,     4,     4,    30,   149,    20,    20,    22,
      22,    20,    84,    22,    31,     6,    33,    34,    35,    50,
       4,    17,    18,    48,     4,    42,     4,     4,     4,    20,
       4,     4,     4,    59,    60,    61,    62,     4,    41,   248,
      41,    41,   251,     4,     4,     4,     4,    73,    74,    75,
      76,    77,    78,   144,   145,    68,    68,    41,   201,    68,
     203,    41,   134,    41,    41,    41,   138,    41,    41,    41,
       4,     4,     4,     4,    41,     3,    12,    40,     0,     4,
      41,    41,    41,    41,     4,    98,    98,     4,     4,    98,
       4,     4,     4,     4,    64,   226,   134,     7,     8,   230,
     138,    11,   233,   129,    40,   147,   148,    41,    41,    41,
      41,    68,   210,   210,   210,   210,    41,     8,     9,   210,
      11,    41,    13,     6,    41,    41,    96,    41,    41,    41,
      41,    40,    42,     8,     9,    10,    11,    20,    13,    45,
       3,    98,   168,   169,   170,   171,    14,    38,     9,    45,
       5,    42,    13,    46,    15,    16,    52,    41,    19,    20,
      53,    29,    30,    38,    15,    16,    40,    42,    19,    20,
      93,    32,   198,   199,    42,    36,    99,    38,    22,    44,
      28,    42,    30,    27,    30,    36,    30,    23,    24,    25,
      26,    42,   277,    39,    42,    37,    42,   282,    42,    94,
      42,   286,    92,    44,     6,   100,    42,    97,    49,   174,
     175,   176,    40,    40,     6,     6,    40,     7,    40,    40,
      40,    40,     8,    40,    21,    40,    40,    12,    40,    40,
      40,    40,    11,    41,     9,    42,    42,    42,    41,    43,
      40,   267,   268,    42,    42,    40,    42,   273,    42,    42,
      10,    40,   278,    41,    13,    38,    40,   283,   284,    40,
      40,    32,    15,    12,    42,    19,    36,    36,    20,    16,
       6,    12,    40,    40,    12,    41,    41,    21,   147,    41,
      44,    44,    43,    41,    41,    41,    41,    12,     6,    18,
      41,    41,    31,    35,    42,    40,    42,    17,    41,    33,
      40,    34,     5,    40,     5,    40,    14,     5,    40,    40,
       5,    41,   206,    41,    87,    42,    42,    41,    41,    41,
     346,    42,    27,    42,    30,    42,    41,    41,    28,    45,
      39,    41,    45,    45,    45,    29,    40,   207,   209,    41,
      -1,    -1,    -1,    42,    41,    41,   210,    37,    41,    41,
      41,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,   151
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    48,    49,     3,     0,    51,   137,    40,    50,
      52,    55,   128,     4,    41,   138,     7,     8,    11,    42,
      54,    57,   130,    45,   137,   137,   137,     3,    40,    53,
      55,    87,    90,   128,   131,   134,    40,    56,    58,    61,
      68,    71,    74,    84,    87,   131,   134,    40,    55,    87,
     128,   129,   131,   134,     5,    41,    41,    41,    41,     9,
      10,    13,    38,    42,    57,     6,    89,    92,   130,    44,
     132,     6,   135,    15,    16,    19,    20,    32,    36,    42,
       6,    59,    40,    62,    63,    63,    69,    63,    72,    75,
      77,    85,    89,   132,   135,    42,    57,    89,   130,   132,
     135,   137,   137,   137,   137,     7,    56,    40,    88,    40,
      91,    93,   104,   110,   116,   129,    40,   133,    40,   136,
     137,   137,   137,   137,   137,   137,     8,    40,    60,    21,
      40,    67,    12,    65,    64,    65,    40,    70,    64,    40,
      73,    40,    76,    40,    78,    81,    40,    61,    68,    71,
      74,    84,    86,    88,   133,   136,    11,    56,    88,   129,
     133,   136,    41,    41,    41,    41,    41,    42,    31,    33,
      34,    35,    42,    95,   106,   112,   118,    42,    42,    41,
      41,    41,    41,    41,    41,    41,    42,   137,    42,    43,
      40,    66,    65,    66,    42,    66,    42,    42,    17,    18,
      40,    71,    79,    71,    82,    42,    62,    69,    72,    75,
      85,    41,     9,   137,   137,   137,   137,    10,    40,    94,
      96,   102,   119,    40,   105,   107,   119,    40,   111,   113,
     119,    40,   117,   119,   122,   125,    38,    13,    32,    41,
      15,    12,    42,    19,    36,    20,   137,   137,    72,    40,
      80,    72,    40,    83,    16,    67,    70,    73,    76,    86,
      41,    41,    41,    41,    41,    41,    22,    27,    30,    42,
      97,     6,   120,    28,    42,    12,   108,   120,    39,    42,
      12,   114,   120,    14,    29,    42,   120,    44,   123,    44,
     126,    41,    41,    41,    41,    43,    21,    41,    41,    41,
      41,    41,    73,    42,    73,    42,    41,   103,   137,   137,
      35,    40,    98,    99,    40,   121,   137,    31,    40,   109,
     121,   137,    33,    40,   115,   121,   137,   137,    34,   121,
      40,   124,    40,   127,    12,    41,    18,    17,    23,    24,
      25,    26,    42,    41,    41,    41,    37,    42,     6,   100,
      42,    41,    41,    42,    41,    41,    42,    41,    41,    41,
      42,    42,    41,    41,    45,    45,    45,    45,    41,   137,
      27,    40,   101,    30,    28,    39,    14,    29,     5,     5,
       5,     5,    41,    41,    42,    41,    41,    41,    41,    41,
      37,    41
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
#line 122 "gramatyka_bison.y"
    {
  restart();
  if (tree)
  {
    delete tree;
  }
  tree = new KML((yyvsp[(3) - (4)].str));
  last_element = tree
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 143 "gramatyka_bison.y"
    {
last_element->AddChild(new Document((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 150 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 165 "gramatyka_bison.y"
    {
last_element->AddChild(new Placemark((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 172 "gramatyka_bison.y"
    {
last_element = last_element->GetParent();
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 190 "gramatyka_bison.y"
    {
last_element->AddChild(new StyleURL((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 197 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 203 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 211 "gramatyka_bison.y"
    {
last_element->AddChild(new Point((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 221 "gramatyka_bison.y"
    {
last_element->AddChild(new Coordinates((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 232 "gramatyka_bison.y"
    {
if (dynamic_cast<Coordinates*>(last_element))
{
  dynamic_cast<Coordinates*>(last_element)->addCoordinate((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str));
}
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 241 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 247 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 253 "gramatyka_bison.y"
    {
last_element->AddChild(new LineString((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 263 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 269 "gramatyka_bison.y"
    {
last_element->AddChild(new LinearRing((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 279 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 285 "gramatyka_bison.y"
    {
last_element->AddChild(new Polygon((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 298 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 308 "gramatyka_bison.y"
    {
last_element->AddChild(new OuterBoundaryIs((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 318 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 324 "gramatyka_bison.y"
    {
last_element->AddChild(new InnerBoundaryIs((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 334 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 341 "gramatyka_bison.y"
    {
last_element->AddChild(new Multigeometry((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 356 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 362 "gramatyka_bison.y"
    {
last_element->AddChild(new Name((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 369 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 375 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 382 "gramatyka_bison.y"
    {
last_element->AddChild(new Style((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 389 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 402 "gramatyka_bison.y"
    {
last_element->AddChild(new IconStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 409 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 421 "gramatyka_bison.y"
    {
last_element->AddChild(new Icon((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 432 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 438 "gramatyka_bison.y"
    {
last_element->AddChild(new Href((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 445 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 451 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 457 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 464 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setX((yyvsp[(4) - (4)].str));
;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 469 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setY((yyvsp[(4) - (4)].str));
;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 474 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setXunits((yyvsp[(4) - (4)].str));
;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 479 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setYunits((yyvsp[(4) - (4)].str));
;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 486 "gramatyka_bison.y"
    {
last_element->AddChild(new LabelStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 493 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 504 "gramatyka_bison.y"
    {
last_element->AddChild(new Scale((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 511 "gramatyka_bison.y"
    {
last_element->AddChild(new numbernode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 517 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 523 "gramatyka_bison.y"
    {
last_element->AddChild(new LineStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 530 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 541 "gramatyka_bison.y"
    {
last_element->AddChild(new Width((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 548 "gramatyka_bison.y"
    {
last_element->AddChild(new numbernode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 554 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 560 "gramatyka_bison.y"
    {
last_element->AddChild(new PolyStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 567 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 579 "gramatyka_bison.y"
    {
last_element->AddChild(new Color((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 586 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 592 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 598 "gramatyka_bison.y"
    {
last_element->AddChild(new Fill((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 606 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 612 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 618 "gramatyka_bison.y"
    {
last_element->AddChild(new Outline((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 625 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 631 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 637 "gramatyka_bison.y"
    {
last_element->AddChild(new Folder((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 644 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 659 "gramatyka_bison.y"
    {
last_element->AddChild(new Visibility((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 666 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 672 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 680 "gramatyka_bison.y"
    {
last_element->AddChild(new Description((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 687 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 693 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 698 "gramatyka_bison.y"
    {(yyval.str) = NULL;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 699 "gramatyka_bison.y"
    {(yyval.str) = (yyvsp[(4) - (4)].str);}
    break;



/* Line 1455 of yacc.c  */
#line 2470 "parser.cpp"
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



