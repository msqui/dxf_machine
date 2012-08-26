#ifndef __MACHINE_HPP__
#define __MACHINE_HPP__

#include <memory>
#include <string>

#include "dxf_machine/dispatcher/Dispatcher.h"
#include "dxf_machine/processor/StatefulProcessor.h"

#include "dxf_machine/file/DxfFile.h"
#include "dxf_machine/model/Model.h"

namespace dxf_machine {

template <typename DispT=dispatcher::Dispatcher,
          typename ProcT=processor::StatefulProcessor>
struct Machine
{
    typedef model::Model ModelT;
    typedef std::unique_ptr<ModelT> ModelPtrT;

    static ModelPtrT process(const std::string& filename)
    {
        type::DxfQueuePtrT tuples;

        file::DxfFile::DxfFilePtrT file_ptr = file::DxfFile::open_file(filename);
        tuples = file_ptr->read_file();

        DispT d(tuples);
        typename ProcT::PtrT p = ProcT::Instance();
        return std::move(p->process(d));
    }
};

}

#endif // __MACHINE_HPP__
