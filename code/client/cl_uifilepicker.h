/*
===========================================================================
Copyright (C) 2015 the OpenMoHAA team

This file is part of OpenMoHAA source code.

OpenMoHAA source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

OpenMoHAA source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenMoHAA source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#ifndef __CL_UIFILEPICKER_H__
#define __CL_UIFILEPICKER_H__

class UIListCtrl;

class FilePickerClass : public USignal {
	UIFloatingWindow *window;
	UIListCtrl *listbox;
	str currentDirectory;
	str rootDirectory;
	str extension;

public:
	CLASS_PROTOTYPE( FilePickerClass );

private:
	void		SetupFiles( void );
	void		GotoParentDirectory( void );
	void		GotoSubDirectory( str subdir );
	void		Initialize( const char *root_directory, const char *current_directory, const char *ext );

protected:
	void			CloseWindow( void );
	void			FileSelected( Event *ev );
	virtual void	FileSelected( str &currentDirectory, str &partialName, str &fullname );
	void			FileChosen( Event *ev );
	virtual void	FileChosen( str &currentDirectory, str &partialName, str &fullname );
	void			OnDeactivated( Event  *ev );

public:
	FilePickerClass();
	~FilePickerClass();

	void Setup( const char *root_directory, const char *current_directory, const char *ext );
};

#endif /* __CL_UIFILEPICKER_H__ */
