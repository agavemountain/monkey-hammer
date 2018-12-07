#pragma once
#include <monkeylib/core/core_exports.h>

namespace Monkey
{
namespace Version
{
	//! \brief Get library version string
	//! \returns
	//!		library version as a string
	MKY_CORE_API const char* GetVersionString();

	//! \brief Get SDK version major number
	MKY_CORE_API unsigned GetVersionMajor();

	//! \brief Get SDK version minor number
	MKY_CORE_API unsigned GetVersionMinor();

	//! \brief Get SDK patch level
	MKY_CORE_API unsigned GetVersionPatch();

	//! \brief Get compiler version string
	//! \returns
	//! 	returns compiler version string
	MKY_CORE_API const char* GetCompilerVersionString();

} //namespace Version
} //namespace Monkey
