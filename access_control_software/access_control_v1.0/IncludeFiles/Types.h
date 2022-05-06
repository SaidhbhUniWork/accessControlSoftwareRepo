#pragma once

#include <string>

using namespace std;

//SYSTEM LOGIN STRINGS
static const string LOGIN_INTRO = " --- MAIN LOGIN ---";
static const string LOGIN_ERROR = "Try again? (Y or N) [0 to quit] : ";
static const char LOGIN_ERROR_REPLY1 = 'n';
static const string LOGIN_ENTRY  = "Enter User Details";
static const string LOGIN_DIVIDE = "------------------";
static const string LOGIN_UNAME_ENTRY = " Username : ";
static const string LOGIN_PWORD_ENTRY = " Password : ";
static const string LOGIN_EXIT = " --- EXITING SYSTEM ---";
static const string LOGIN_AD_MENU = " --- ADMIN MENU ---";
static const string LOGIN_U_MENU = " --- MAIN MENU ---";
static const string LOGIN_U_RES = ". Resource Access";
static const string LOGIN_U_PASS = ". Change Password";
static const string LOGIN_U_CHOICE = "(0 to exit)";
static const string LOGIN_M_RES = ". Resource Access" ;
static const string LOGIN_M_PASS = ". Change Password";
static const string LOGIN_M_REQ = ". User Access Requests";
static const string LOGIN_M_LOG = ". View File Logs";
static const string LOGIN_M_CHOICE = "(0 to exit)";
static const string LOGIN_M_SELECT = "Please select menu option (";
static const string LOGIN_NO_FILE = "File does not exist.";
static const string LOGIN_NO_PATH = "No File path";
static const string LOGIN_NO_LOG = "No log";
static const string LOGIN_ERROR_INPUT = "Incorrect input, please select 1 - ";

// AUTHENTICATION INFO MESSAGE STRINGS
static const string AUTH_INFO_OPEN_ERROR = "ERROR: Cannot open file : ";
static const string AUTH_INFO_CLOSE_ERROR = "ERROR: Cannot close file : ";

// AUTHENTICATION MESSAGE STRINGS
static const string LOGGED = " --- LOGGED IN ---";
static const string LOGGED_ERROR = "\nInvalid Username/Password\n";
static const string AUTH_FILENAME = "enc_userLogins.txt";

// ACCESS LOG FILE STRINGS
//static const string SOLN_DIR_FPATH = "C:/Users/Saidhbh/Documents/College Files/Final Project/accessControlSoftwareRepo/access_control_software/";
//static const string SOLN_DIR_FPATH = "($(SolutionDir))"; 
static const string SYSTEM_ACCESS_FPATH = "..\\access_control_v1.0\\LogFiles\\Access_LogFiles\\AccessSuccess\\";
static const string DENIED_ACCESS_FPATH = "..\\access_control_v1.0\\LogFiles\\Access_LogFiles\\AccessDenied\\";
static const string SYSTEM_ACCESS_LOGGER = "_accessSuccess.txt";
static const string DENIED_ACCESS_LOGGER = "_accessDenied.txt";

// RESOURCE LOG FILE STRING
static const string RESOURCE_ACCESS_FPATH = "..\\access_control_v1.0\\LogFiles/Resource_LogFiles\\ResourceSuccess\\";
static const string RESOURCE_DENIED_FPATH = "..\\access_control_v1.0/LogFiles\\Resource_LogFiles\\ResourceDenied\\";
static const string RESOURCE_ACCESS_LOGGER = "_resourceSuccess.txt";
static const string RESOURCE_DENIED_LOGGER = "_resourceDenied.txt";

// SUBJECT STRINGS
static const string SUB_FNAME_PRIV = "enc_assignPrivileges.txt";
static const string SUB_FOPEN_ERROR = "Could not open file : ";

// PASSWORD STRINGS
static const string PASS_FNAME = "enc_userLogins.txt";
static const string PASS_FOPEN_ERROR = "Could not open file : ";
static const string PASS_INTRO = " --- CREATE NEW PASSWORD ---";
static const string PASS_NEWPASS_INFO = "Please enter your new password";
static const string PASS_REQ1 = " - Between 8 and 20 characters";
static const string PASS_REQ2 = " - At least one number [0 to 9]";
static const string PASS_REQ3 = " - At least one symbol [# ? ! @ $ % ^ & * -]";
static const string PASS_REQ4 = " - At least one uppercase letter";
static const string PASS_REQ5 = " - At least one lowercase letter";
// ROLE STRINGS
static const string SIMPLE_FOPEN_ERROR = "Error opening file : ";
static const string SIMPLE_FCLOSE_ERROR = "Error closing file : ";

// ENCRYPTION CONSTANTS
static const int ENC_KEY = 32;
static const int ENC_IV = 16;
static const int ENC_KEYGEN_LOW_PARAM = 33;
static const int ENC_KEYGEN_HIGH_PARAM = 126;
static const int ENC_KEYGEN_ERROR = 48;
static const int ENC_MAX_CIPHER_ARRAY = 255;

// LOGGER VIEWER CONSTANTS
static const int MAX_DAY = 31;
static const int MAX_MONTH = 12;
static const int MAX_YEAR = 2022;

// LOGGER VIEWER STRINGS
static const string VIEW_FILE_DATE_INPUT = "Enter File Date : ";
static const string VIEW_FILE_DAY = "Day : ";
static const string VIEW_FILE_MONTH = "Month : ";
static const string VIEW_FILE_YEAR = "Year : ";
static const string VIEW_FILE_FILEDATE = "Is this correct? : ";
static const string VIEW_FILE_DATE_CONFIRM = "(Y or N) : ";

// REFERENCE MONITOR STRINGS
static const string REF_FILENAME = "enc_accessMatrix.txt";
static const string REF_NO_FILE = "Could not open File : ";
static const string REF_CLOSE_FAIL = "File close failed : ";
static const string REF_NO_LOG = "No log";
static const string REF_PERMS_ERROR = "Subject Permission error: ";

// VALIDATION CONSTANTS
static const int VALID_MAX_PWORD = 8;