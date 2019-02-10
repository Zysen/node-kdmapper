{
	'conditions': [
        ['OS=="win"', {
            'targets': [
				{
					'target_name': 'kdmapper',
					'sources': ["<(module_root_dir)\\kdmapper\\kdmapper\\*.cpp", 'node-kdmapper.cc'],
					"include_dirs" : ["<(module_root_dir)\\include\\", "<(module_root_dir)\\kdmapper\\kdmapper\\"],					
					"libraries": [ "<(module_root_dir)\\libs\\<(target_arch)\\atls.lib"],
					"msvs_settings" : {"VCCLCompilerTool" : {"AdditionalOptions" : [
						"/std:c++17"
					]}}
				}
			]
        }]
	]
}

