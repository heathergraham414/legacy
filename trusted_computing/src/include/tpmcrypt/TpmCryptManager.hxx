// Copyright (C) 2008, 2009 by Sirrix AG security technologies
// Copyright (C) 2010 by Philipp Deppenwiese
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

/**
 * @file        TpmCryptManager.hxx
 * @brief       The management functions...
 * @version     $Revision: 792 $
 * @date        Last modification at $Date: 2009-08-05 15:03:56 +0200 (Wed, 05 Aug 2009) $ by $Author: goericke $
 */


#ifndef _TPMCRYPTMANAGER_HXX
#define	_TPMCRYPTMANAGER_HXX

#include <TpmCryptConfigfile.hxx>
#include <TpmCryptLogin.hxx>
#include <TpmCryptStorage.hxx>
#include <TpmCryptSubject.hxx>
#include <TpmCryptESD.hxx>
#include <TpmCryptSearch.hxx>
#include <TpmCryptVolume.hxx>

// Volume Types
enum myTpmCryptPlatformType
{
    PLATFORMTYPE_BEGIN = 0,
    PLATFORMTYPE_PCR00,
    PLATFORMTYPE_PCR01,
    PLATFORMTYPE_PCR02,
    PLATFORMTYPE_PCR03,
    PLATFORMTYPE_PCR04,
    PLATFORMTYPE_PCR05,
    PLATFORMTYPE_PCR06,
    PLATFORMTYPE_PCR07,
    PLATFORMTYPE_PCR08,
    PLATFORMTYPE_PCR09,
    PLATFORMTYPE_PCR10,
    PLATFORMTYPE_PCR11,
    PLATFORMTYPE_PCR12,
    PLATFORMTYPE_PCR13,
    PLATFORMTYPE_PCR14,
    PLATFORMTYPE_PCR15,
    PLATFORMTYPE_PCR16,
    PLATFORMTYPE_PCR17,
    PLATFORMTYPE_PCR18,
    PLATFORMTYPE_PCR19,
    PLATFORMTYPE_PCR20,
    PLATFORMTYPE_PCR21,
    PLATFORMTYPE_PCR22,
    PLATFORMTYPE_PCR23,
    PLATFORMTYPE_END
};

const std::string TpmCryptPlatformType_PCR00    = "PCR00";
const std::string TpmCryptPlatformType_PCR01    = "PCR01";
const std::string TpmCryptPlatformType_PCR02    = "PCR02";
const std::string TpmCryptPlatformType_PCR03    = "PCR03";
const std::string TpmCryptPlatformType_PCR04    = "PCR04";
const std::string TpmCryptPlatformType_PCR05    = "PCR05";
const std::string TpmCryptPlatformType_PCR06    = "PCR06";
const std::string TpmCryptPlatformType_PCR07    = "PCR07";
const std::string TpmCryptPlatformType_PCR08    = "PCR08";
const std::string TpmCryptPlatformType_PCR09    = "PCR09";
const std::string TpmCryptPlatformType_PCR10    = "PCR10";
const std::string TpmCryptPlatformType_PCR11    = "PCR11";
const std::string TpmCryptPlatformType_PCR12    = "PCR12";
const std::string TpmCryptPlatformType_PCR13    = "PCR13";
const std::string TpmCryptPlatformType_PCR14    = "PCR14";
const std::string TpmCryptPlatformType_PCR15    = "PCR15";
const std::string TpmCryptPlatformType_PCR16    = "PCR16";
const std::string TpmCryptPlatformType_PCR17   = "PCR17";
const std::string TpmCryptPlatformType_PCR18   = "PCR18";
const std::string TpmCryptPlatformType_PCR19   = "PCR19";
const std::string TpmCryptPlatformType_PCR20   = "PCR20";
const std::string TpmCryptPlatformType_PCR21   = "PCR21";
const std::string TpmCryptPlatformType_PCR22   = "PCR22";
const std::string TpmCryptPlatformType_PCR23   = "PCR23";


/*!
  *  @brief adds a secret sharing sheme to a volume in the database
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  *  @param &mySSSStorage, TpmCryptStorage, points to the current secret sharing scheme database
  */
void TpmCryptAddSSSToVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage, TpmCryptStorage &mySSSStorage);

/*!
  *  @brief adds a subject to a group in the database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */   

void TpmCryptAddSubjectToVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

/*!
  *  @brief changes the path, where the volume can be found
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */
void TpmCryptAttachVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

/*!
  *  @brief creates a new admin
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  */
void TpmCryptCreateAdmin(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief creates a new group
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */

void TpmCryptCreatePlatform(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief creates a new token
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  */
void TpmCryptCreateToken(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief creates a new user
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  */
void TpmCryptCreateUser(TpmCryptStorage &mySubjectStorage);

void TpmCryptCreateESD			 ( TpmCryptStorage &myESDStorage );



/*!
  *  @brief deletes a user from a volume
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */
void TpmCryptCreateVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

/*!
  *  @brief deletes an admin in the database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */
void TpmCryptDeleteAdmin(TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

/*!
  *  @brief deletes a group from a volume
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */

void TpmCryptDeletePlatform(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief deletes a secret sharing scheme from a volume
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  *  @param &mySSSStorage, TpmCryptStorage, points to the current secret sharing scheme database
  */
void TpmCryptDeleteSSSFromVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage, TpmCryptStorage &mySSSStorage);

/*!
  *  @brief deletes a subject from a group
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */
void TpmCryptDeleteSubjectFromGroup(TpmCryptStorage &myGroupStorage, TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief deletes a subject from a volume
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */
void TpmCryptDeleteSubjectFromVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

/*!
  *  @brief deletes a token in the database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  */
void TpmCryptDeleteToken(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief deletes a user in the database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */
void TpmCryptDeleteUser(TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

/*!
  *  @brief deletes a volume in the database
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */
void TpmCryptDeleteVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param groupParam, string, contains the calling parameter
  *  @param &myConfigfile, TpmCryptConfigfile, contains the current TpmCrypt configuration
  */

void TpmCryptImportUser(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief imports a volume in the database
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */
void TpmCryptImportVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param initParam, string, contains the calling parameter
  *  @param &myConfigfile, TpmCryptConfigfile, contains the current TpmCrypt configuration
  */
void TpmCryptInit     ( string initParam, TpmCryptConfigfile &myConfigfile );

/*!
  *  @brief prints all admins to the screen
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @return bool, determines whether or not the operation was successful
  */
bool TpmCryptListAdmins(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief prints all groups to the screen
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  *  @return bool, determines whether or not the operation was successful
  */

bool TpmCryptListUsers(TpmCryptStorage &mySubjectStorage, bool includeAdmins);

/*!
  *  @brief prints all volumes to the screen
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @return bool, determines whether or not the operation was successful
  */
bool TpmCryptListVolumes(TpmCryptStorage &myVolumeStorage);

/*!
  *  @brief prints all groups in a given  volume to the screen
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */

bool TpmCryptListPlatforms(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief returns all secret sharing schemes, that have access to a volume
  *  @param &myVolumeStorage, TpmCryptStorage, points to the current volume database
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  *  @param &mySSSStorage, TpmCryptStorage, points to the current secret sharing scheme database
  *  @return string, contains the sss, that have access
  */
string TpmCryptListSSSInVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage, TpmCryptStorage &mySSSStorage);

/*!
  *  @brief prints all subjects of a given group to the screen
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @param &myGroupStorage, TpmCryptStorage, points to the current group database
  */

void TpmCryptListSubjectsInVolume(TpmCryptStorage &myVolumeStorage, TpmCryptStorage &mySubjectStorage, TpmCryptStorage &myGroupStorage);

void TpmCryptShowESD				 ( TpmCryptStorage &myESDStorage );

vector<int> TpmCryptChooseAllPCR();

/*!
  *  @brief prints all tokens to the screen
  *  @param &mySubjectStorage, TpmCryptStorage, points to the current subject database
  *  @return bool, determines whether or not the operation was successful
  */
bool TpmCryptListToken(TpmCryptStorage &mySubjectStorage);

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param platformParam, string, contains the calling parameter
  *  @param &myConfigfile, TpmCryptConfigfile, contains the current TpmCrypt configuration
  */
void TpmCryptPlatformManagement   ( string platformParam, TpmCryptConfigfile &myConfigfile );

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param SSSParam, string, contains the calling parameter
  *  @param &myConfigfile, TpmCryptConfigfile, contains the current TpmCrypt configuration
  */
void TpmCryptSSSManagement        ( string SSSParam, TpmCryptConfigfile &myConfigfile );

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param platformParam, string, contains the calling parameter
  *  @param &myConfigfile, TpmCryptConfigfile, contains the current TpmCrypt configuration
  */
void TpmCryptTokenManagement   ( string platformParam, TpmCryptConfigfile &myConfigfile );

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param userParam, string, contains the calling parameter
  *  @param &myConfigfile, TpmCryptConfigfile, contains the current TpmCrypt configuration
  */
void TpmCryptUserManagement       ( string userParam, TpmCryptConfigfile &myConfigfile );

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param volumeParam, string, contains the calling parameter
  *  @param &myConfigfile, TpmCryptConfigfile, contains the current TpmCrypt configuration
  */
void TpmCryptVolumeManagement     ( string volumeParam, TpmCryptConfigfile &myConfigfile );

void TpmCryptESDManagement		 ( string esdParam, TpmCryptConfigfile &myConfigfile );

void TpmCryptDestroyKeys		();



// this method is actually implemented in TpmCryptLogin.cxx
TpmCryptSubject* getCurrentAdmin(TpmCryptStorage &mySubjectStorage);

#endif	/* _TPMCRYPTMANAGER_HXX */
