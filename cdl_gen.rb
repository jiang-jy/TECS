# signatureを生成するため
require "json"
require 'fileutils'
# Echonet Lite Device Description in JSON
devdesc_json_fname = "appendix_v3-1-6r5/EL_DeviceDescription_3_1_6r5.json"

# Read Device Description (String)
devdesc_json = File.read(devdesc_json_fname)

# Convert JSON String to Hash
DevDesc = JSON[devdesc_json]
Devices = DevDesc["devices"]
Definitions = DevDesc["definitions"]

def parse_properties (val,fileName)
    val.each{ |prop_id,val2|
        if val2['oneOf'] then

        else
            if val2['accessRule']['set'] == 'required' then
                accessRule = 'set'
                parse_required(val2,fileName,accessRule)
            end

            if val2['accessRule']['get'] == 'required' then 
                accessRule = 'get'
                parse_required(val2,fileName,accessRule)
            end
        end
    }
end

def parse_required(val2,fileName,accessRule)
    propertyName = val2['propertyName']['en']
    if val2['data']['$ref'] then
    ref = val2['data']['$ref'].sub( /#\/definitions\//, "" )
    val3 = Definitions[ref]
    parse_definitions(val3,propertyName,fileName,accessRule)
    elsif val2['data']['type'] == 'state' then
    val3 = val2['data']
    parse_definitions(val3,propertyName,fileName,accessRule)
    elsif val2['data']['oneOf'] then
    val2['data']['oneOf'].each{ |val3|
        if val3['$ref'] then
        ref = val3['$ref'].sub( /#\/definitions\//, "" )
        val4 = Definitions[ref]
        parse_definitions(val4,propertyName,fileName,accessRule)
        else
        end
    }
    else
    end
end

def parse_definitions(val,propertyName,fileName,accessRule)
        if val['type'] == 'number' then
            type = val['format']
            propertyName = font_change(propertyName)
            size = property_format_size(type)
            min = val['minimum']
            max = val['maximum']
            print_signature_number("    ",propertyName,fileName,accessRule)
        elsif val['type'] == 'state' then
            size = val['size']
            type = property_data_type(size)
            propertyName = font_change(propertyName)
            print_signature_state("    ",val,propertyName,fileName,accessRule)
        else
        end
    
end

def print_signature_state(indent,val,propertyName,fileName,accessRule)
    val['enum'].each{ |edt|
        stateName = font_change(edt['state']['en'])
        fileName.print("#{indent}void #{accessRule}#{propertyName}_#{stateName}( );\n")
    }

end

def print_signature_number(indent,propertyName,fileName,accessRule)
    fileName.print("#{indent}void #{accessRule}#{propertyName}( );\n")
end


def property_data_type (size)
    if size == 1 then
        return 'uint8_t'
    elsif size == 2 then
        return 'uint16_t'
    elsif size == 4 then
        return 'uint32_t'
    end
end

def property_format_size (type)
    if type == 'uint8'
        return 1
    elsif type == 'uint16'
        return 2
    elsif type == 'uint32'
        return 4
    end
end

def font_change(name)
    return name.gsub("/"," ").split(/ |\_|\-/).map(&:capitalize).join(" ").gsub(/\s+/, '')
end


def file_output(val)
    className = font_change(val['className']['en'])
    FileUtils.mkdir_p("lib/#{className}/src") # 建立多重路径
    cdl = File.open("lib/#{className}/src/t#{className}.cdl","w+")
    cdl.print("signature s#{className} {\n")
    parse_properties(val['elProperties'],cdl)
    cdl.puts("    void setOperatingStatus_ON( );
    void getOperatingStatus_ON( );
    void setOperatingStatus_OFF( );
    void getOperatingStatus_OFF( );
    void setFaultStatus_Fault( );
    void getFaultStatus_Fault( );
    void setFaultStatus_NoFault( );
    void getFaultStatus_NoFault( );
};
")
    cdl.puts("celltype t#{className} {
    entry s#{className} e#{className};
};")
    cdl.close
end



Devices.each{ |id, val|
    if val['oneOf'] then
        val['oneOf'].each{|val2|
            file_output(val2)
        }
    elsif val['className'] == nil then
        #print "*** #{id} has no class name ***\n"
    elsif val['className']['en'] then   
        file_output(val)
        #print( "#{val['className']['en']} = #{id}\n" )
    elsif val['className']['ja'] then
        #print( "#{val['className']['ja']} = #{id}\n" )
    else
        #print "### #{id} has class name but has neither 'ja' nor 'en' ***\n"
    end
}


# if true then
# Dir.mkdir("gen")
# cdl = File.open("gen/demo.cdl","w+")
# cdl.puts("hello world")
# cdl.close
# else
# FileUtils.rm_r ("gen")
# end