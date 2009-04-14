// This file is part of BlueSky
// 
// BlueSky is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.
// 
// BlueSky is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with BlueSky; if not, see <http://www.gnu.org/licenses/>.

#ifndef BS_MATCUBE_H_
#define BS_MATCUBE_H_

// ������������ ����� ��� BS-�������
#include "bs_object_base.h"
#include "bs_command.h"

// ������������ ����� ��� BS-�������, ������� ����� �������� ����� ����� (?)
#ifdef BSPY_EXPORTING_PLUGIN
#include "py_bs_tree.h"
#include "py_bs_object_base.h"
#include "py_bs_command.h"
#include "bs_plugin_common.h"
#endif

namespace blue_sky {
	namespace python {
		// ���� �����
		void register_obj();
	}

	// ����� ����� - ����������� �� �������� ������ ��� ���� BS-��������
	class BS_API_PLUGIN bs_matcube : public objbase
	{
		// ���� �����
		friend void python::register_obj();
		// ���� �����
		static int py_factory_index;
	public:
		// ������������ �������� ������������� ���������� BLUE_SKY_TYPE_DECL(bs_matcube) ����
		// ����������
		~bs_matcube();

		// �������� �������
		const char * test();
		// ���� ����������� � ����������� stdout
		void dump();

		// ��������� ������� ����� (��������� ������)
		void set_size(int sizei, int sizej);

		// ������� ����������� � ������ ��� ���������� ������
		void paste_to_matlab(char* name);
		// ��������� ����������� �� ������� ��� ���������� ������
		void copy_from_matlab(char* name);
		// ���������� ������������ ������� ������� 
		void exec_in_matlab(char* name);
		
		// ������ ������������� ���������������� ������� ��� ���������: ���������� ���� �������� �� 1 
		void sample_func();

		// ���� �����
		int get_py_factory_index();
	private:
		// ������ �����
		int sizei_,sizej_;
		// �������� �����
		double **cubeval_;
		
		// ���������, �������������� ��� (?) � ��������� ������������
		BLUE_SKY_TYPE_DECL(bs_matcube);
	};


	// ����� - ������� �����, ����������� �� �������� ������ ��� ���� BS-�������� � �� �������� ������ ��� ������
	class BS_API_PLUGIN matcube_command : public objbase, public combase
	{
	public:
		// ����� ���������� �������
		sp_com execute();
		// ����� undo �������
		void unexecute();
		// �������� �������
		void test();
		
		// ���� �����
		void dispose() const {
			delete this;
		}

		// ���������, �������������� ��� (?) � ��������� ������������
		BLUE_SKY_TYPE_DECL(matcube_command)
	};
}

#endif
