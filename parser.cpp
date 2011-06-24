
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
     HEADING_SYM = 293,
     VISIBILITY_SYM = 294,
     WIDTH_SYM = 295,
     TAG_OPEN = 296,
     TAG_CLOSE = 297,
     TAG_END = 298,
     COMMA = 299,
     BOOLEAN_VAL = 300,
     EQ = 301,
     SYM_NOT_VALID = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 64 "gramatyka_bison.y"

		std::string *str;



/* Line 214 of yacc.c  */
#line 224 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 236 "parser.cpp"

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
#define YYLAST   369

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNRULES -- Number of states.  */
#define YYNSTATES  400

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      45,    46,    47
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
     349,   354,   359,   362,   367,   369,   374,   379,   380,   385,
     390,   395,   397,   402,   408,   409,   414,   419,   424,   429,
     434,   439,   440,   445,   450,   455,   457,   462,   467,   472,
     473,   478,   483,   488,   490,   495,   500,   505,   506,   511,
     516,   521,   526,   528,   533,   538,   540,   545,   550,   552,
     557,   562,   567,   568,   573,   578,   583,   588,   593,   595,
     600,   605,   607,   612,   613,   618,   619
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      49,     0,    -1,    50,    52,    51,    -1,    41,     3,   141,
      42,    -1,    41,    43,     3,    42,    -1,    -1,    52,    53,
      55,    54,    -1,    52,    56,    58,    57,    -1,    52,   132,
     134,   133,    -1,    41,     7,   141,    42,    -1,    41,    43,
       7,    42,    -1,    -1,    55,    56,    58,    57,    -1,    55,
      88,    90,    89,    -1,    55,    91,    93,    92,    -1,    55,
     132,   134,   133,    -1,    55,   138,   139,   140,    -1,    55,
     135,   136,   137,    -1,    41,     8,   141,    42,    -1,    41,
      43,     8,    42,    -1,    -1,    58,    62,    63,    68,    -1,
      58,    69,    70,    71,    -1,    58,    72,    73,    74,    -1,
      58,    75,    76,    77,    -1,    58,    85,    86,    87,    -1,
      58,    59,    60,    61,    -1,    58,    88,    90,    89,    -1,
      58,   135,   136,   137,    -1,    58,   138,   139,   140,    -1,
      41,    32,   141,    42,    -1,     6,    -1,    41,    43,    32,
      42,    -1,    41,    15,   141,    42,    -1,    64,    66,    67,
      -1,    41,    21,   141,    42,    -1,    66,    -1,    65,    66,
      -1,    12,    44,    12,    44,    12,    -1,    41,    43,    21,
      42,    -1,    41,    43,    15,    42,    -1,    41,    19,   141,
      42,    -1,    64,    65,    67,    -1,    41,    43,    19,    42,
      -1,    41,    36,   141,    42,    -1,    64,    65,    67,    -1,
      41,    43,    36,    42,    -1,    41,    20,   141,    42,    -1,
      78,    79,    80,    81,    -1,    41,    43,    20,    42,    -1,
      -1,    78,    82,    83,    84,    -1,    41,    18,   141,    42,
      -1,    72,    73,    74,    -1,    41,    43,    18,    42,    -1,
      41,    17,   141,    42,    -1,    72,    73,    74,    -1,    41,
      43,    17,    42,    -1,    41,    16,   141,    42,    -1,    -1,
      86,    62,    63,    68,    -1,    86,    69,    70,    71,    -1,
      86,    72,    73,    74,    -1,    86,    75,    76,    77,    -1,
      86,    85,    86,    87,    -1,    41,    43,    16,    42,    -1,
      41,     9,   141,    42,    -1,    41,    43,     9,    42,    -1,
       6,    -1,    41,    10,   141,    42,    -1,    41,    43,    10,
      42,    -1,    -1,    93,    94,    96,    95,    -1,    93,   108,
     110,   109,    -1,    93,   114,   116,   115,    -1,    93,   120,
     122,   121,    -1,    41,    35,   141,    42,    -1,    41,    43,
      35,    42,    -1,    -1,    96,   123,   124,   125,    -1,    96,
      97,    98,    99,    -1,    96,   100,   101,   102,    -1,    96,
     106,    -1,    41,    38,   141,    42,    -1,    12,    -1,    41,
      43,    38,    42,    -1,    41,    27,   141,    42,    -1,    -1,
     101,   103,   104,   105,    -1,    41,    43,    27,    42,    -1,
      41,    37,   141,    42,    -1,     6,    -1,    41,    43,    37,
      42,    -1,    41,    22,   107,    43,    42,    -1,    -1,   107,
      25,    46,     5,    -1,   107,    26,    46,     5,    -1,   107,
      24,    46,     5,    -1,   107,    23,    46,     5,    -1,    41,
      31,   141,    42,    -1,    41,    43,    31,    42,    -1,    -1,
     110,   123,   124,   125,    -1,   110,   111,   112,   113,    -1,
      41,    28,   141,    42,    -1,    12,    -1,    41,    43,    28,
      42,    -1,    41,    33,   141,    42,    -1,    41,    43,    33,
      42,    -1,    -1,   116,   123,   124,   125,    -1,   116,   117,
     118,   119,    -1,    41,    40,   141,    42,    -1,    12,    -1,
      41,    43,    40,    42,    -1,    41,    34,   141,    42,    -1,
      41,    43,    34,    42,    -1,    -1,   122,   123,   124,   125,
      -1,   122,   126,   127,   128,    -1,   122,   129,   130,   131,
      -1,    41,    30,   141,    42,    -1,     6,    -1,    41,    43,
      30,    42,    -1,    41,    14,   141,    42,    -1,    45,    -1,
      41,    43,    14,    42,    -1,    41,    29,   141,    42,    -1,
      45,    -1,    41,    43,    29,    42,    -1,    41,    11,   141,
      42,    -1,    41,    43,    11,    42,    -1,    -1,   134,    88,
      90,    89,    -1,   134,   135,   136,   137,    -1,   134,   138,
     139,   140,    -1,   134,    56,    58,    57,    -1,    41,    39,
     141,    42,    -1,    45,    -1,    41,    43,    39,    42,    -1,
      41,    13,   141,    42,    -1,     6,    -1,    41,    43,    13,
      42,    -1,    -1,   141,   142,    46,     5,    -1,    -1,     4,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   125,   136,   139,   140,   141,   142,   145,
     152,   158,   159,   160,   161,   162,   163,   164,   167,   174,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     192,   199,   205,   213,   220,   223,   230,   231,   234,   243,
     249,   255,   262,   265,   271,   278,   281,   287,   294,   300,
     306,   307,   310,   317,   320,   326,   333,   336,   343,   350,
     351,   352,   353,   354,   355,   358,   364,   371,   377,   384,
     391,   397,   398,   399,   400,   401,   404,   411,   417,   418,
     419,   420,   421,   424,   431,   437,   443,   450,   451,   454,
     460,   467,   473,   479,   485,   486,   491,   496,   501,   508,
     515,   521,   522,   523,   526,   533,   539,   545,   552,   558,
     559,   560,   563,   570,   576,   582,   589,   595,   596,   597,
     598,   601,   608,   614,   620,   628,   634,   640,   647,   653,
     659,   666,   672,   673,   674,   675,   676,   680,   687,   693,
     701,   708,   714,   720,   721,   724,   725
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
  "TAG_CLOSE", "TAG_END", "COMMA", "BOOLEAN_VAL", "EQ", "SYM_NOT_VALID",
  "$accept", "input", "kml_start", "kml_end", "kml", "document_start",
  "document_end", "document", "placemark_start", "placemark_end",
  "placemark", "style_url_start", "style_url", "style_url_end",
  "point_start", "point", "coordinates_start", "coordinates",
  "one_coordinates", "coordinates_end", "point_end", "line_string_start",
  "line_string", "line_string_end", "linear_ring_start", "linear_ring",
  "linear_ring_end", "polygon_start", "polygon", "polygon_end",
  "polygon_more", "outer_boundary_is_start", "outer_boundary_is",
  "outer_boundary_is_end", "inner_boundary_is_start", "inner_boundary_is",
  "inner_boundary_is_end", "multigeometry_start", "multigeometry",
  "multigeometry_end", "name_start", "name_end", "name", "style_start",
  "style_end", "style", "icon_style_start", "icon_style_end", "icon_style",
  "heading_start", "heading", "heading_end", "icon_start", "icon",
  "icon_end", "href_start", "href", "href_end", "hotspot",
  "hotspot_options", "label_style_start", "label_style_end", "label_style",
  "scale_start", "scale", "scale_end", "line_style_start",
  "line_style_end", "line_style", "width_start", "width", "width_end",
  "poly_style_start", "poly_style_end", "poly_style", "color_start",
  "color", "color_end", "fill_start", "fill", "fill_end", "outline_start",
  "outline", "outline_end", "folder_start", "folder_end", "folder",
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    52,    52,    52,    52,    53,
      54,    55,    55,    55,    55,    55,    55,    55,    56,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    61,    62,    63,    64,    65,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      86,    86,    86,    86,    86,    87,    88,    89,    90,    91,
      92,    93,    93,    93,    93,    93,    94,    95,    96,    96,
      96,    96,    96,    97,    98,    99,   100,   101,   101,   102,
     103,   104,   105,   106,   107,   107,   107,   107,   107,   108,
     109,   110,   110,   110,   111,   112,   113,   114,   115,   116,
     116,   116,   117,   118,   119,   120,   121,   122,   122,   122,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   134,   134,   134,   134,   135,   136,   137,
     138,   139,   140,   141,   141,   142,   142
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
       4,     4,     2,     4,     1,     4,     4,     0,     4,     4,
       4,     1,     4,     5,     0,     4,     4,     4,     4,     4,
       4,     0,     4,     4,     4,     1,     4,     4,     4,     0,
       4,     4,     4,     1,     4,     4,     4,     0,     4,     4,
       4,     4,     1,     4,     4,     1,     4,     4,     1,     4,
       4,     4,     0,     4,     4,     4,     4,     4,     1,     4,
       4,     1,     4,     0,     4,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,   143,     1,     0,   145,     0,     2,
      11,    20,   132,   146,     3,     0,   143,   143,   143,     0,
       0,     0,     0,     0,   145,   145,   145,     0,     0,     6,
      20,     0,    71,   132,     0,     0,     0,     7,     0,     0,
       0,     0,    50,    59,     0,     0,     0,     0,    20,     0,
       8,     0,     0,   144,     9,    18,   130,     4,   143,   143,
     143,   143,     0,     0,    68,     0,     0,     0,   138,     0,
     141,     0,   143,   143,   143,   143,   143,   143,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     145,   145,   145,     0,    12,     0,    13,     0,    14,    78,
     101,   109,   117,    15,     0,    17,     0,    16,   145,   145,
     145,   145,   145,   145,     0,     0,    26,   143,     0,    21,
       0,     0,     0,    36,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,     0,     0,     0,    50,    59,
      25,    27,    28,    29,     0,   136,   133,   134,   135,    66,
      69,   140,   137,    10,     0,   143,   143,   143,   143,     0,
       0,     0,     0,     0,     0,     0,    33,    58,    41,    47,
      30,    44,    19,     0,   145,     0,     0,     0,    34,    37,
      42,     0,    45,     0,     0,   143,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,     0,
     145,   145,   145,   145,     0,     0,    72,     0,    87,    82,
       0,     0,    73,     0,     0,     0,    74,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,   145,   145,     0,     0,    48,     0,
       0,    51,     0,    60,    61,    62,    63,    64,    67,    99,
     107,   115,    76,    70,    94,   143,   143,   143,     0,    84,
       0,     0,   122,     0,   143,     0,   105,     0,     0,   143,
       0,   113,     0,     0,   143,   143,     0,     0,   125,     0,
     128,     0,   139,   142,    32,    40,     0,     0,    43,    46,
      49,    55,    52,    53,     0,    56,     0,    65,     0,   145,
     145,   145,     0,     0,    80,     0,    81,     0,     0,    79,
     145,     0,     0,   103,   102,   145,     0,     0,   111,   110,
     145,   145,     0,   118,     0,   119,     0,   120,    38,    39,
       0,     0,     0,     0,     0,     0,     0,    86,   121,    83,
      77,     0,   143,     0,    91,     0,     0,   104,   100,     0,
     112,   108,     0,   124,   127,   116,     0,     0,    54,    57,
       0,     0,     0,     0,    93,     0,   145,     0,     0,    88,
       0,     0,     0,     0,     0,    98,    97,    95,    96,    85,
      90,    89,     0,   123,   106,   114,   126,   129,     0,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,     6,    10,    29,    20,    48,    37,
      21,    38,    80,   126,    39,    82,    86,   132,   133,   188,
     129,    40,    85,   135,    41,    87,   138,    42,    88,   140,
      89,   142,   199,   248,   143,   201,   251,    43,    90,   150,
      44,   106,    65,    32,   108,    66,   109,   216,   170,   217,
     270,   314,   218,   271,   316,   317,   355,   379,   219,   308,
     110,   222,   171,   223,   277,   323,   111,   226,   172,   227,
     282,   328,   112,   230,   173,   220,   273,   319,   232,   289,
     335,   233,   291,   337,    12,    50,    22,    45,    69,   115,
      46,    71,   117,     7,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -197
static const yytype_int16 yypact[] =
{
      41,    26,   116,  -197,  -197,  -197,   102,     7,    95,  -197,
    -197,  -197,  -197,  -197,  -197,    82,  -197,  -197,  -197,    86,
     105,   127,   128,   176,     9,    12,    13,   151,   131,  -197,
    -197,   194,  -197,  -197,   163,   203,   146,  -197,   206,   178,
     178,   178,  -197,  -197,   194,   163,   203,   145,  -197,   194,
    -197,   163,   203,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,   213,   127,  -197,   180,   181,   128,  -197,   182,
    -197,   183,  -197,  -197,  -197,  -197,  -197,  -197,   217,  -197,
     185,   207,   186,   218,   218,   188,   218,   190,   191,   192,
     193,   180,   182,   183,   224,   127,   180,   182,   183,    29,
      30,    31,    32,   195,  -197,   196,  -197,   170,  -197,  -197,
    -197,  -197,  -197,  -197,   197,  -197,   198,  -197,    33,    34,
      35,    36,    37,    42,   200,   201,  -197,  -197,   202,  -197,
     199,   205,    96,  -197,   204,  -197,    96,   209,  -197,   210,
    -197,   139,   214,   214,   156,   178,   178,   178,  -197,  -197,
    -197,  -197,  -197,  -197,   212,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,   227,  -197,  -197,  -197,  -197,   228,
     215,   216,   219,   220,   223,   235,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,   232,    43,   244,   253,   229,  -197,  -197,
    -197,   247,  -197,   231,   250,  -197,  -197,   237,   178,   230,
     178,   233,   259,   186,   188,   190,   191,   193,  -197,   234,
      44,    48,    76,    77,   236,   164,  -197,   265,  -197,  -197,
     273,   117,  -197,   268,   273,   -12,  -197,   269,   273,   134,
    -197,   273,   238,   239,   240,   243,   245,  -197,   246,   242,
     270,   248,   251,   252,    83,    84,   190,   249,  -197,   190,
     254,  -197,   256,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,   260,  -197,
     255,   258,  -197,   261,  -197,   272,  -197,   263,   261,  -197,
     267,  -197,   264,   261,  -197,  -197,   274,   261,  -197,   266,
    -197,   271,  -197,  -197,  -197,  -197,   277,   275,  -197,  -197,
    -197,  -197,  -197,  -197,   283,  -197,   289,  -197,   172,    87,
      88,    89,   276,   278,  -197,   -17,  -197,   303,   279,  -197,
      90,   281,   282,  -197,  -197,    91,   284,   285,  -197,  -197,
      92,    93,   287,  -197,   288,  -197,   290,  -197,  -197,  -197,
     292,   293,   286,   291,   294,   295,   296,  -197,  -197,  -197,
    -197,   301,  -197,   297,  -197,   302,   280,  -197,  -197,   299,
    -197,  -197,   304,  -197,  -197,  -197,   300,   313,  -197,  -197,
     306,   308,   310,   311,  -197,   305,    94,   307,   309,  -197,
     312,   314,   315,   316,   317,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,   318,  -197,  -197,  -197,  -197,  -197,   319,  -197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,   104,    20,
     -18,  -197,  -197,  -197,   -87,   174,   -32,   262,   -68,    78,
     142,   -86,   184,   147,   -80,  -133,  -196,   -85,   221,   140,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,   -84,   171,   143,
      -1,   -64,    55,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,    45,   -41,  -178,  -197,  -197,
    -197,  -197,  -197,  -197,   333,   298,   327,     2,    56,   114,
       3,   121,    19,   -16,  -197
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      24,    25,    26,   145,   146,   148,   149,    83,    84,   255,
     147,    13,    63,    13,   205,   131,    13,    13,   266,    31,
     352,    49,    34,    35,    51,    52,   353,   151,   279,     4,
      95,   280,   156,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    99,   100,   101,   102,    13,    13,    13,    14,
     303,    54,    13,   305,    55,    56,   118,   119,   120,   121,
     122,   123,   198,   200,   189,   246,    49,   249,   189,    51,
      52,   159,   160,   161,   162,   176,   177,   178,   179,   180,
      13,    13,     1,   104,   181,   237,   259,    13,    13,    27,
     260,    13,    13,    13,    13,    13,    13,    13,    13,    91,
     324,    92,    16,    17,    96,   329,    18,    97,   130,   333,
      11,   184,   153,    83,    84,   155,     5,   158,   261,   262,
     145,   146,   148,   149,    30,   301,   302,   147,    23,   347,
     348,   349,   357,   360,   363,   364,   390,   187,    19,    17,
      58,    59,    18,     8,    60,   274,    28,   266,   284,   210,
     211,   212,   213,    17,    58,    58,   195,   196,    60,    60,
     275,    72,    73,   285,   266,    74,    75,    93,    36,    47,
      61,    72,    73,    98,    62,    74,    75,   286,    76,   244,
     245,    53,    77,   278,    61,    61,   264,   283,    94,    78,
     287,   265,    77,    57,   266,   342,   343,   344,   345,   202,
      64,   165,   267,   166,   167,   168,   152,   268,    68,    70,
     190,   157,    79,   169,   192,   346,   224,   228,   231,    81,
     103,   105,   107,   114,   116,   124,   125,   128,   127,   134,
     130,   137,   139,   141,   144,   154,   209,   163,   214,   164,
     174,   175,   182,   186,   183,   185,   187,   191,   235,   309,
     310,   311,   193,   194,   208,   197,   215,   221,   320,   238,
     225,   229,   234,   325,   236,   239,   241,   242,   330,   331,
     243,   247,   240,    77,   250,   252,   258,   269,   263,   272,
     276,   281,   292,   288,   290,   293,   296,   294,   295,   338,
     298,   297,   304,   299,   300,   312,   313,   306,   307,   315,
     326,   340,   318,   321,   322,   327,   341,   334,   332,   354,
     380,   385,   336,   386,   383,   387,   388,   339,   350,   203,
     207,   351,   356,   358,   377,   359,   361,   381,   362,   365,
     204,   366,   370,   367,   368,   369,   376,   371,   374,   375,
     372,   373,   384,   378,   382,   253,   256,   389,   136,   391,
     257,   254,   392,    33,   393,   398,   394,   395,   396,   397,
      67,   399,     0,     0,     0,   113,     0,     0,     0,   206
};

static const yytype_int16 yycheck[] =
{
      16,    17,    18,    90,    90,    90,    90,    39,    40,   205,
      90,     4,    30,     4,   147,    83,     4,     4,    30,    20,
      37,    22,    20,    20,    22,    22,    43,    91,    40,     3,
      48,    43,    96,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    58,    59,    60,    61,     4,     4,     4,    42,
     246,    42,     4,   249,    42,    42,    72,    73,    74,    75,
      76,    77,   142,   143,   132,   198,    67,   200,   136,    67,
      67,    42,    42,    42,    42,    42,    42,    42,    42,    42,
       4,     4,    41,    63,    42,    42,    42,     4,     4,     3,
      42,     4,     4,     4,     4,     4,     4,     4,     4,    44,
     278,    45,     7,     8,    49,   283,    11,    51,    12,   287,
       6,   127,    93,   145,   146,    95,     0,    98,    42,    42,
     207,   207,   207,   207,    20,    42,    42,   207,    46,    42,
      42,    42,    42,    42,    42,    42,    42,    41,    43,     8,
       9,    10,    11,    41,    13,    28,    41,    30,    14,   165,
     166,   167,   168,     8,     9,     9,    17,    18,    13,    13,
      43,    15,    16,    29,    30,    19,    20,    46,    41,    41,
      39,    15,    16,    52,    43,    19,    20,    43,    32,   195,
     196,     5,    36,   224,    39,    39,    22,   228,    43,    43,
     231,    27,    36,    42,    30,    23,    24,    25,    26,    43,
       6,    31,    38,    33,    34,    35,    92,    43,    45,     6,
     132,    97,     6,    43,   136,    43,   171,   172,   173,    41,
       7,    41,    41,    41,    41,     8,    41,    41,    21,    41,
      12,    41,    41,    41,    41,    11,     9,    42,    10,    43,
      43,    43,    42,    44,    43,    43,    41,    43,    13,   265,
     266,   267,    43,    43,    42,    41,    41,    41,   274,    15,
      41,    41,    39,   279,    32,    12,    19,    36,   284,   285,
      20,    41,    43,    36,    41,    16,    42,    12,    42,     6,
      12,    12,    42,    45,    45,    42,    44,    42,    42,    12,
      42,    21,    43,    42,    42,    35,    41,    43,    42,    41,
      33,    18,    41,    31,    41,    41,    17,    41,    34,     6,
      30,     5,    41,     5,    14,     5,     5,    42,    42,   145,
     149,    43,    43,    42,    27,    43,    42,    28,    43,    42,
     146,    43,    46,    43,    42,    42,   352,    46,    42,    38,
      46,    46,    29,    41,    40,   203,   206,    42,    86,    42,
     207,   204,    43,    20,    42,    37,    42,    42,    42,    42,
      33,    42,    -1,    -1,    -1,    67,    -1,    -1,    -1,   148
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    49,    50,     3,     0,    52,   141,    41,    51,
      53,    56,   132,     4,    42,   142,     7,     8,    11,    43,
      55,    58,   134,    46,   141,   141,   141,     3,    41,    54,
      56,    88,    91,   132,   135,   138,    41,    57,    59,    62,
      69,    72,    75,    85,    88,   135,   138,    41,    56,    88,
     133,   135,   138,     5,    42,    42,    42,    42,     9,    10,
      13,    39,    43,    58,     6,    90,    93,   134,    45,   136,
       6,   139,    15,    16,    19,    20,    32,    36,    43,     6,
      60,    41,    63,    64,    64,    70,    64,    73,    76,    78,
      86,    90,   136,   139,    43,    58,    90,   136,   139,   141,
     141,   141,   141,     7,    57,    41,    89,    41,    92,    94,
     108,   114,   120,   133,    41,   137,    41,   140,   141,   141,
     141,   141,   141,   141,     8,    41,    61,    21,    41,    68,
      12,    66,    65,    66,    41,    71,    65,    41,    74,    41,
      77,    41,    79,    82,    41,    62,    69,    72,    75,    85,
      87,    89,   137,   140,    11,    57,    89,   137,   140,    42,
      42,    42,    42,    42,    43,    31,    33,    34,    35,    43,
      96,   110,   116,   122,    43,    43,    42,    42,    42,    42,
      42,    42,    42,    43,   141,    43,    44,    41,    67,    66,
      67,    43,    67,    43,    43,    17,    18,    41,    72,    80,
      72,    83,    43,    63,    70,    73,    76,    86,    42,     9,
     141,   141,   141,   141,    10,    41,    95,    97,   100,   106,
     123,    41,   109,   111,   123,    41,   115,   117,   123,    41,
     121,   123,   126,   129,    39,    13,    32,    42,    15,    12,
      43,    19,    36,    20,   141,   141,    73,    41,    81,    73,
      41,    84,    16,    68,    71,    74,    77,    87,    42,    42,
      42,    42,    42,    42,    22,    27,    30,    38,    43,    12,
      98,   101,     6,   124,    28,    43,    12,   112,   124,    40,
      43,    12,   118,   124,    14,    29,    43,   124,    45,   127,
      45,   130,    42,    42,    42,    42,    44,    21,    42,    42,
      42,    42,    42,    74,    43,    74,    43,    42,   107,   141,
     141,   141,    35,    41,    99,    41,   102,   103,    41,   125,
     141,    31,    41,   113,   125,   141,    33,    41,   119,   125,
     141,   141,    34,   125,    41,   128,    41,   131,    12,    42,
      18,    17,    23,    24,    25,    26,    43,    42,    42,    42,
      42,    43,    37,    43,     6,   104,    43,    42,    42,    43,
      42,    42,    43,    42,    42,    42,    43,    43,    42,    42,
      46,    46,    46,    46,    42,    38,   141,    27,    41,   105,
      30,    28,    40,    14,    29,     5,     5,     5,     5,    42,
      42,    42,    43,    42,    42,    42,    42,    42,    37,    42
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
        case 2:

/* Line 1455 of yacc.c  */
#line 120 "gramatyka_bison.y"
    {
restart();
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 126 "gramatyka_bison.y"
    {
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
#line 146 "gramatyka_bison.y"
    {
last_element->AddChild(new Document((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 153 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 168 "gramatyka_bison.y"
    {
last_element->AddChild(new Placemark((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 175 "gramatyka_bison.y"
    {
last_element = last_element->GetParent();
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 193 "gramatyka_bison.y"
    {
last_element->AddChild(new StyleURL((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 200 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 206 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 214 "gramatyka_bison.y"
    {
last_element->AddChild(new Point((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 224 "gramatyka_bison.y"
    {
last_element->AddChild(new Coordinates((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 235 "gramatyka_bison.y"
    {
if (dynamic_cast<Coordinates*>(last_element))
{
  dynamic_cast<Coordinates*>(last_element)->addCoordinate((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str));
}
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 244 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 250 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 256 "gramatyka_bison.y"
    {
last_element->AddChild(new LineString((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 266 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 272 "gramatyka_bison.y"
    {
last_element->AddChild(new LinearRing((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 282 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 288 "gramatyka_bison.y"
    {
last_element->AddChild(new Polygon((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 301 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 311 "gramatyka_bison.y"
    {
last_element->AddChild(new OuterBoundaryIs((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 321 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 327 "gramatyka_bison.y"
    {
last_element->AddChild(new InnerBoundaryIs((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 337 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 344 "gramatyka_bison.y"
    {
last_element->AddChild(new Multigeometry((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 359 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 365 "gramatyka_bison.y"
    {
last_element->AddChild(new Name((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 372 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 378 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 385 "gramatyka_bison.y"
    {
last_element->AddChild(new Style((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 392 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 405 "gramatyka_bison.y"
    {
last_element->AddChild(new IconStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 412 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 425 "gramatyka_bison.y"
    {
last_element->AddChild(new Heading((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 432 "gramatyka_bison.y"
    {
last_element->AddChild(new numbernode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 438 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 444 "gramatyka_bison.y"
    {
last_element->AddChild(new Icon((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 455 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 461 "gramatyka_bison.y"
    {
last_element->AddChild(new Href((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 468 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 474 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 480 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 487 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setX((yyvsp[(4) - (4)].str));
;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 492 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setY((yyvsp[(4) - (4)].str));
;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 497 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setXunits((yyvsp[(4) - (4)].str));
;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 502 "gramatyka_bison.y"
    {
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setYunits((yyvsp[(4) - (4)].str));
;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 509 "gramatyka_bison.y"
    {
last_element->AddChild(new LabelStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 516 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 527 "gramatyka_bison.y"
    {
last_element->AddChild(new Scale((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 534 "gramatyka_bison.y"
    {
last_element->AddChild(new numbernode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 540 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 546 "gramatyka_bison.y"
    {
last_element->AddChild(new LineStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 553 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 564 "gramatyka_bison.y"
    {
last_element->AddChild(new Width((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 571 "gramatyka_bison.y"
    {
last_element->AddChild(new numbernode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 577 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 583 "gramatyka_bison.y"
    {
last_element->AddChild(new PolyStyle((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 590 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 602 "gramatyka_bison.y"
    {
last_element->AddChild(new Color((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 609 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 615 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 621 "gramatyka_bison.y"
    {
last_element->AddChild(new Fill((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 629 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 635 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 641 "gramatyka_bison.y"
    {
last_element->AddChild(new Outline((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 648 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 654 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 660 "gramatyka_bison.y"
    {
last_element->AddChild(new Folder((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 667 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 681 "gramatyka_bison.y"
    {
last_element->AddChild(new Visibility((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 688 "gramatyka_bison.y"
    {
last_element->AddChild(new boolnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 694 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 702 "gramatyka_bison.y"
    {
last_element->AddChild(new Description((yyvsp[(3) - (4)].str)));
last_element = last_element->GetLastChild();
;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 709 "gramatyka_bison.y"
    {
last_element->AddChild(new textnode((yyvsp[(1) - (1)].str)));
;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 715 "gramatyka_bison.y"
    {
last_element = last_element->GetParent()
;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 720 "gramatyka_bison.y"
    {(yyval.str) = NULL;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 721 "gramatyka_bison.y"
    {(yyval.str) = (yyvsp[(4) - (4)].str);}
    break;



/* Line 1455 of yacc.c  */
#line 2506 "parser.cpp"
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



