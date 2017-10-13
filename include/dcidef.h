/*
 * $Header: dcidfn.h $ 
 */

/* Copyright (c) 2010, BaseSoft Inc.  All rights reserved.  */
 
#ifndef DCIDFN_H
#define DCIDFN_H

#include "dcitypes.h"

/* Data Types */

#define SQLT_CHR  1	                                     /* character string */
#define SQLT_NUM  2                                               /* numeric */
#define SQLT_INT  3                                               /* integer */
#define SQLT_FLT  4                                 /* Floating point number */
#define SQLT_STR  5                                /* zero terminated string */

#define SQLT_LNG  8                                                  /* long */
#define SQLT_VCS  9                             /* Variable character string */

#define SQLT_DAT  12                                                 /* date */
#define SQLT_BIN  23                                  /* binary data(DTYBIN) */
#define SQLT_LBI  24                                          /* long binary */
#define SQLT_UIN  68                                     /* unsigned integer */
#define SQLT_LVC  94                                  /* Longer longs (char) */
#define SQLT_LVB  95                                   /* Longer long binary */
#define SQLT_AFC  96                                      /* Ansi fixed char */
#define SQLT_AVC  97                                        /* Ansi Var char */
#define SQLT_CUR  102                                        /* cursor  type */

#define SQLT_REF  110                                            /* ref type */

#define SQLT_CLOB 112                                       /* character lob */
#define SQLT_BLOB 113                                          /* binary lob */

#define SQLT_RSET 116                                     /* result set type */

#define SQLT_ODT  156                                        /* DCIDate type */

/* datetimes and intervals */
#define SQLT_DATE                      184                      /* ANSI Date */
#define SQLT_TIME                      185                           /* TIME */
#define SQLT_TIME_TZ                   186            /* TIME WITH TIME ZONE */
#define SQLT_TIMESTAMP                 187                      /* TIMESTAMP */
#define SQLT_TIMESTAMP_TZ              188       /* TIMESTAMP WITH TIME ZONE */
#define SQLT_INTERVAL_YM               189         /* INTERVAL YEAR TO MONTH */
#define SQLT_INTERVAL_DS               190         /* INTERVAL DAY TO SECOND */

/* CHAR/NCHAR/VARCHAR2/NVARCHAR2/CLOB/NCLOB char set "form" information */
#define SQLCS_IMPLICIT 1     /* for CHAR, VARCHAR2, CLOB w/o a specified set */
#define SQLCS_NCHAR    2                  /* for NCHAR, NCHAR VARYING, NCLOB */
#define SQLCS_EXPLICIT 3   /* for CHAR, etc, with "CHARACTER SET ..." syntax */

/* Param Mode */
enum DCITypeParamMode
{
	DCI_TYPEPARAM_IN = 0,                                                /* in */
	DCI_TYPEPARAM_OUT,                                                  /* out */
	DCI_TYPEPARAM_INOUT,                                             /* in-out */
};
typedef enum DCITypeParamMode DCITypeParamMode;

/* Type Code */
#define DCI_TYPECODE_REF         SQLT_REF        /* SQL/OTS OBJECT REFERENCE */
#define DCI_TYPECODE_DATE        SQLT_DAT              /* SQL DATE  OTS DATE */
#define DCI_TYPECODE_SIGNED8     27      /* SQL SIGNED INTEGER(8)  OTS SINT8 */
#define DCI_TYPECODE_REAL        21                /* SQL REAL  OTS SQL_REAL */
#define DCI_TYPECODE_DOUBLE      22  /* SQL DOUBLE PRECISION  OTS SQL_DOUBLE */
#define DCI_TYPECODE_FLOAT       SQLT_FLT      /* SQL FLOAT(P)  OTS FLOAT(P) */
#define DCI_TYPECODE_NUMBER      SQLT_NUM/* SQL NUMBER(P S)  OTS NUMBER(P S) */
#define DCI_TYPECODE_DECIMAL     SQLT_PDN

#define DCI_TYPECODE_SMALLINT    246           /* SQL SMALLINT  OTS SMALLINT */
#define DCI_TYPECODE_INTEGER     SQLT_INT        /* SQL INTEGER  OTS INTEGER */

#define DCI_TYPECODE_RAW         SQLT_LVB          /* SQL RAW(N)  OTS RAW(N) */

#define DCI_TYPECODE_CHAR        SQLT_AFC    /* SQL CHAR(N)  OTS SQL_CHAR(N) */
#define DCI_TYPECODE_VARCHAR     SQLT_CHR
#define DCI_TYPECODE_VARCHAR2    SQLT_VCS

#define DCI_TYPECODE_BLOB        SQLT_BLOB    /* SQL/OTS BINARY LARGE OBJECT */
#define DCI_TYPECODE_CLOB        SQLT_CLOB /* SQL/OTS CHARACTER LARGE OBJECT */

#define DCI_TYPECODE_TIME        SQLT_TIME                   /* SQL/OTS TIME */
#define DCI_TYPECODE_TIME_TZ     SQLT_TIME_TZ             /* SQL/OTS TIME_TZ */
#define DCI_TYPECODE_TIMESTAMP   SQLT_TIMESTAMP         /* SQL/OTS TIMESTAMP */
#define DCI_TYPECODE_TIMESTAMP_TZ  SQLT_TIMESTAMP_TZ /* SQL/OTS TIMESTAMP_TZ */

#define DCI_TYPECODE_TIMESTAMP_LTZ  SQLT_TIMESTAMP_LTZ /* TIMESTAMP_LTZ */

#define DCI_TYPECODE_INTERVAL_YM SQLT_INTERVAL_YM   /* SQL/OTS INTRVL YR-MON */
#define DCI_TYPECODE_INTERVAL_DS SQLT_INTERVAL_DS  /* SQL/OTS INTRVL DAY-SEC */

typedef ub2 DCITypeCode;


/* DCI_*_PIECE defines the piece types that are returned or set
*/
#define DCI_ONE_PIECE   0                 /* there or this is the only piece */
#define DCI_FIRST_PIECE 1                        /* the first of many pieces */
#define DCI_NEXT_PIECE  2                         /* the next of many pieces */
#define DCI_LAST_PIECE  3                   /* the last piece of this column */

/*-----------------------------Handle Types----------------------------------*/

#define DCI_HTYPE_ENV            1                     /* environment handle */
#define DCI_HTYPE_ERROR          2                           /* error handle */
#define DCI_HTYPE_SVCCTX         3                         /* service handle */
#define DCI_HTYPE_STMT           4                       /* statement handle */
#define DCI_HTYPE_BIND           5                            /* bind handle */
#define DCI_HTYPE_DEFINE         6                          /* define handle */
#define DCI_HTYPE_DESCRIBE       7                        /* describe handle */
#define DCI_HTYPE_SERVER         8                          /* server handle */
#define DCI_HTYPE_SESSION        9                  /* authentication handle */
#define DCI_HTYPE_TRANS         10                     /* transaction handle */

#define DCI_HTYPE_DIRPATH_CTX   14                    /* direct path context */
#define DCI_HTYPE_DIRPATH_COLUMN_ARRAY 15        /* direct path column array */
#define DCI_HTYPE_DIRPATH_STREAM       16              /* direct path stream */


/*-------------------------Descriptor Types----------------------------------*/
#define DCI_DTYPE_LOB 50                                     /* lob  locator */
#define DCI_DTYPE_SNAP 51                             /* snapshot descriptor */
#define DCI_DTYPE_PARAM 53
						 /* a parameter descriptor obtained from DCIParamGet */

/*-------------------------Object Ptr Types----------------------------------*/
#define DCI_OTYPE_NAME 1                                      /* object name */
#define DCI_OTYPE_REF  2                                       /* REF to TDO */
#define DCI_OTYPE_PTR  3                                       /* PTR to TDO */

/*=============================Attribute Types===============================*/

#define DCI_ATTR_SERVER           6                     /* the server handle */
#define DCI_ATTR_SESSION          7               /* the user session handle */

#define DCI_ATTR_ROW_COUNT        9             /* the rows processed so far */
#define DCI_ATTR_PREFETCH_ROWS    11  /* sets the number of rows to prefetch */
#define DCI_ATTR_PARAM_COUNT      18  /* number of column in the select list */

#define DCI_ATTR_USERNAME         22                   /* username attribute */
#define DCI_ATTR_PASSWORD         23                   /* password attribute */

#define DCI_ATTR_CHARSET_ID       31                     /* Character Set ID */
#define DCI_ATTR_CHARSET_FORM     32                   /* Character Set Form */

#define DCI_ATTR_LOBEMPTY		45                            /* empty lob ? */

#define DCI_ATTR_DATEFORMAT       75           /* default date format string */
#define DCI_ATTR_BUF_SIZE         77                          /* buffer size */
#define DCI_ATTR_DIRPATH_MODE     78        /* mode of direct path operation */

#define DCI_ATTR_NUM_ROWS         81       /* number of rows in column array */
#define DCI_ATTR_COL_COUNT        82              /* columns of column array
processed so far.       */
#define DCI_ATTR_NUM_COLS         102                   /* number of columns */
#define DCI_ATTR_LIST_COLUMNS     103        /* parameter of the column list */
#define DCI_ATTR_LIST_ARGUMENTS   108      /* parameter of the argument list */
#define DCI_ATTR_LIST_SUBPROGRAMS 109    /* parameter of the subprogram list */
#define DCI_ATTR_REF_TDO          110          /* REF to the type descriptor */
#define DCI_ATTR_LINK             111              /* the database link name */

#define DCI_ATTR_TIMESTAMP        119             /* timestamp of the object */
#define DCI_ATTR_NUM_ATTRS        120                /* number of sttributes */
#define DCI_ATTR_NUM_PARAMS       121                /* number of parameters */
#define DCI_ATTR_PTYPE            123           /* type of info described by */
#define DCI_ATTR_PARAM            124                /* parameter descriptor */
#define DCI_ATTR_LTYPE            128                           /* list type */

#define DCI_ATTR_OBJ_NAME         134           /* top level schema obj name */
#define DCI_ATTR_OBJ_SCHEMA       135                         /* schema name */
#define DCI_ATTR_OBJ_ID           136          /* top level schema object id */

#define DCI_ATTR_DIRPATH_INPUT    151      /* input in text or stream format */
#define DCI_DIRPATH_INPUT_TEXT     0x01
#define DCI_DIRPATH_INPUT_STREAM   0x02
#define DCI_DIRPATH_INPUT_UNKNOWN  0x04

#define DCI_ATTR_DIRPATH_OID      187             /* loading into an OID col */
#define DCI_ATTR_BIND_COUNT       190             /* number of bind postions */

#define DCI_ATTR_ROWS_FETCHED     197 /* rows fetched in last call */

#define DCI_CRED_RDBMS      1                  /* database username/password */

/*------------------------Error Return Values--------------------------------*/
#define DCI_SUCCESS           0            /* maps to SQL_SUCCESS of SAG CLI */
#define DCI_SUCCESS_WITH_INFO 1             /* maps to SQL_SUCCESS_WITH_INFO */
#define DCI_NO_DATA           100                     /* maps to SQL_NO_DATA */
#define DCI_ERROR             -1                        /* maps to SQL_ERROR */
#define DCI_INVALID_HANDLE    -2               /* maps to SQL_INVALID_HANDLE */
#define DCI_NEED_DATA         99                    /* maps to SQL_NEED_DATA */


#define DCI_CONTINUE -24200    /* Continue with the body of the DCI function */

#define DCI_NTV_SYNTAX 1    /* Use what so ever is the native lang of server */

/*------------------------Scrollable Cursor Fetch Options------------------- 
* For non-scrollable cursor, the only valid (and default) orientation is 
* DCI_FETCH_NEXT
*/
#define DCI_FETCH_CURRENT 0x01               /* refetching current position  */
#define DCI_FETCH_NEXT    0x02                                   /* next row */
#define DCI_FETCH_FIRST   0x04                /* first row of the result set */
#define DCI_FETCH_LAST    0x08             /* the last row of the result set */
#define DCI_FETCH_PRIOR   0x10       /* the previous row relative to current */
#define DCI_FETCH_ABSOLUTE 0x20                /* absolute offset from first */
#define DCI_FETCH_RELATIVE 0x40                /* offset relative to current */


#define DCI_DEFAULT         0x00000000 
/* the default value for parameters and attributes */

#define DCI_THREADED        0x00000001      /* appl. in threaded environment */

/*----------------------- Execution Modes -----------------------------------*/
#define DCI_BATCH_MODE        0x01      /* batch the statement for execution */
#define DCI_EXACT_FETCH       0x02         /* fetch the exact rows specified */
#define DCI_KEEP_FETCH_STATE  0x04                                 /* unused */
#define DCI_STMT_SCROLLABLE_READONLY 0x08     /* if result set is scrollable */
#define DCI_DESCRIBE_ONLY     0x10            /* only describe the statement */
#define DCI_COMMIT_ON_SUCCESS 0x20        /* commit, if successful execution */
#define DCI_NON_BLOCKING      0x40                           /* non-blocking */
#define DCI_BATCH_ERRORS      0x80             /* batch errors in array dmls */
#define DCI_PARSE_ONLY        0x100              /* only parse the statement */
#define DCI_EXACT_FETCH_RESERVED_1 0x200                         /* reserved */
#define DCI_SHOW_DML_WARNINGS 0x400   
/* return DCI_SUCCESS_WITH_INFO for delete/update w/no where clause */


/*=======================Describe Handle Parameter Attributes ===============*/

/* Attributes common to Columns and Stored Procs */
#define DCI_ATTR_DATA_SIZE      1                /* maximum size of the data */
#define DCI_ATTR_DATA_TYPE      2     /* the SQL type of the column/argument */
#define DCI_ATTR_DISP_SIZE      3                        /* the display size */
#define DCI_ATTR_NAME           4         /* the name of the column/argument */
#define DCI_ATTR_PRECISION      5                /* precision if number type */
#define DCI_ATTR_SCALE          6                    /* scale if number type */
#define DCI_ATTR_IS_NULL        7                            /* is it null ? */
#define DCI_ATTR_TYPE_NAME      8
/* name of the named data type or a package name for package private types */
#define DCI_ATTR_SCHEMA_NAME    9             /* the schema name */
#define DCI_ATTR_SUB_NAME       10      /* type name if package private type */
#define DCI_ATTR_POSITION       11
/* relative position of col/arg in the list of cols/args */


/* Only Stored Procs */
#define DCI_ATTR_LEVEL          211            /* level for structured types */
#define DCI_ATTR_HAS_DEFAULT    212                   /* has a default value */
#define DCI_ATTR_IOMODE         213                         /* in, out inout */
#define DCI_ATTR_RADIX          214                       /* returns a radix */
#define DCI_ATTR_NUM_ARGS       215             /* total number of arguments */

#define DCI_ATTR_TYPECODE                  216       /* object or collection */


#define DCI_ATTR_CHAR_USED                 285      /* char length semantics */
#define DCI_ATTR_CHAR_SIZE                 286                /* char length */

/*---------------------------End Describe Handle Attributes -----------------*/


/*-----------------------Handle Definitions----------------------------------*/
typedef struct DCIEnv           DCIEnv;            /* DCI environment handle */
typedef struct DCIError         DCIError;                /* DCI error handle */
typedef struct DCISvcCtx        DCISvcCtx;             /* DCI service handle */
typedef struct DCIStmt          DCIStmt;             /* DCI statement handle */
typedef struct DCIBind          DCIBind;                  /* DCI bind handle */
typedef struct DCIDefine        DCIDefine;              /* DCI Define handle */
typedef struct DCIDescribe      DCIDescribe;          /* DCI Describe handle */
typedef struct DCIServer        DCIServer;              /* DCI Server handle */
typedef struct DCISession       DCISession;     /* DCI Authentication handle */
typedef struct DCITrans         DCITrans;          /* DCI Transaction handle */

typedef struct DCIDirPathCtx      DCIDirPathCtx;                  /* context */
typedef struct DCIDirPathColArray DCIDirPathColArray;        /* column array */
typedef struct DCIDirPathStream   DCIDirPathStream;                /* stream */

/*-----------------------Descriptor Definitions------------------------------*/
typedef struct DCISnapshot      DCISnapshot;      /* DCI snapshot descriptor */
typedef struct DCILobLocator    DCILobLocator; /* DCI Lob Locator descriptor */
typedef struct DCIParam         DCIParam;        /* DCI PARameter descriptor */


typedef ub4 DCILobOffset;
typedef ub4 DCILobLength;

enum DCILobMode
{
	DCI_LOBMODE_READONLY = 1,                                     /* read-only */
	DCI_LOBMODE_READWRITE = 2             /* read_write for internal lobs only */
};
typedef enum DCILobMode DCILobMode;


/*--------------------------- LOB open modes --------------------------------*/
#define DCI_LOB_READONLY 1              /* readonly mode open for ILOB types */
#define DCI_LOB_READWRITE 2                /* read write mode open for ILOBs */

/*--------------------------- DCI Statement Types ---------------------------*/

#define  DCI_STMT_SELECT  1                              /* select statement */
#define  DCI_STMT_UPDATE  2                              /* update statement */
#define  DCI_STMT_DELETE  3                              /* delete statement */
#define  DCI_STMT_INSERT  4                              /* Insert Statement */
#define  DCI_STMT_CREATE  5                              /* create statement */
#define  DCI_STMT_DROP    6                                /* drop statement */
#define  DCI_STMT_ALTER   7                               /* alter statement */
#define  DCI_STMT_BEGIN   8                   /* begin ... (pl/sql statement)*/
#define  DCI_STMT_DECLARE 9                /* declare .. (pl/sql statement ) */
/*---------------------------------------------------------------------------*/

/*--------------------------- DCI Parameter Types ---------------------------*/
#define DCI_PTYPE_UNK                 0                         /* unknown   */
#define DCI_PTYPE_TABLE               1                         /* table     */
#define DCI_PTYPE_VIEW                2                         /* view      */
#define DCI_PTYPE_PROC                3                         /* procedure */
#define DCI_PTYPE_FUNC                4                         /* function  */
#define DCI_PTYPE_PKG                 5                         /* package   */
#define DCI_PTYPE_TYPE                6                 /* user-defined type */
#define DCI_PTYPE_SYN                 7                         /* synonym   */
#define DCI_PTYPE_SEQ                 8                         /* sequence  */
#define DCI_PTYPE_COL                 9                         /* column    */
#define DCI_PTYPE_ARG                 10                        /* argument  */
#define DCI_PTYPE_LIST                11                        /* list      */
#define DCI_PTYPE_TYPE_ATTR           12    /* user-defined type's attribute */
#define DCI_PTYPE_TYPE_COLL           13        /* collection type's element */
#define DCI_PTYPE_TYPE_METHOD         14       /* user-defined type's method */
#define DCI_PTYPE_TYPE_ARG            15   /* user-defined type method's arg */
#define DCI_PTYPE_TYPE_RESULT         16/* user-defined type method's result */
#define DCI_PTYPE_SCHEMA              17                           /* schema */
#define DCI_PTYPE_DATABASE            18                         /* database */
#define DCI_PTYPE_RULE                19                             /* rule */
#define DCI_PTYPE_RULE_SET            20                         /* rule set */
#define DCI_PTYPE_EVALUATION_CONTEXT  21               /* evaluation context */
#define DCI_PTYPE_TABLE_ALIAS         22                      /* table alias */
#define DCI_PTYPE_VARIABLE_TYPE       23                    /* variable type */
#define DCI_PTYPE_NAME_VALUE          24                  /* name value pair */

/*---------------------------------------------------------------------------*/

/*----------------------------- DCI List Types ------------------------------*/
#define DCI_LTYPE_UNK           0                               /* unknown   */
#define DCI_LTYPE_COLUMN        1                             /* column list */
#define DCI_LTYPE_ARG_PROC      2                 /* procedure argument list */
#define DCI_LTYPE_ARG_FUNC      3                  /* function argument list */
#define DCI_LTYPE_SUBPRG        4                         /* subprogram list */
#define DCI_LTYPE_TYPE_ATTR     5                          /* type attribute */
#define DCI_LTYPE_TYPE_METHOD   6                             /* type method */
#define DCI_LTYPE_TYPE_ARG_PROC 7    /* type method w/o result argument list */
#define DCI_LTYPE_TYPE_ARG_FUNC 8      /* type method w/result argument list */
#define DCI_LTYPE_SCH_OBJ       9                      /* schema object list */
#define DCI_LTYPE_DB_SCH        10                   /* database schema list */
#define DCI_LTYPE_TYPE_SUBTYPE  11                           /* subtype list */
#define DCI_LTYPE_TABLE_ALIAS   12                       /* table alias list */
#define DCI_LTYPE_VARIABLE_TYPE 13                     /* variable type list */
#define DCI_LTYPE_NAME_VALUE    14                        /* name value list */

/*----- values for cflg argument to DCIDirpathColArrayEntrySet -----*/
#define DCI_DIRPATH_COL_COMPLETE 0                /* column data is complete */
#define DCI_DIRPATH_COL_NULL     1                         /* column is null */
#define DCI_DIRPATH_COL_PARTIAL  2                 /* column data is partial */

/*----- values for action parameter to DCIDirPathDataSave -----*/
#define DCI_DIRPATH_DATASAVE_SAVEONLY 0              /* data save point only */
#define DCI_DIRPATH_DATASAVE_FINISH   1           /* execute finishing logic */
#define DCI_DIRPATH_DATASAVE_PARTIAL  2       
      /* save portion of input data (before space error occurred) and finish */

/*--------------------------- OBJECT INDICATOR ------------------------------*/

typedef sb2 DCIInd;
/*
* DCIInd -- a variable of this type contains (null) indicator information
*/

#define DCI_IND_NOTNULL (DCIInd)0                                /* not NULL */
#define DCI_IND_NULL (DCIInd)(-1)                                    /* NULL */
#define DCI_IND_BADNULL (DCIInd)(-2)                             /* BAD NULL */
#define DCI_IND_NOTNULLABLE (DCIInd)(-3)                     /* not NULLable */

#endif  /* DCIDFN_H */
