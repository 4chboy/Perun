#!/usr/bin/env python3

import logging
import sys
from pathlib import Path

logger = logging.getLogger("collect_sources")

modules = [
    'libs/core',
    'libs/utils',
    'libs/window',
    'examples/test'
]


def collect_sources(module_path):
    sources = []
    for p in ['*.hpp', '*.h', '*.cpp', '*.c']:
        sources.extend(module_path.rglob(p))

    sources = sorted(sources, key=lambda p: (p.parent, p))

    def is_pch_header(f):
        return f.stem.endswith('_pch')

    def is_not_pch_header(f):
        return not f.stem.endswith('_pch')

    main_sources = list(filter(is_not_pch_header, sources))
    pch_sources = list(filter(is_pch_header, sources))

    return main_sources, pch_sources


def write_cmake_source_files(module_name, module_path, main_sources, pch_sources):
    def write_sources(variable_name, sources):
        f.write('set(' + variable_name + '\n')

        prev_file = Path()
        for s in sources:
            if prev_file.parent != s.parent and prev_file != Path():
                f.write('\n')

            f.write(f'    ${{CMAKE_CURRENT_LIST_DIR}}/{s.relative_to(module_path).as_posix()}\n')
            prev_file = s

        f.write(')\n')

    main_variable_name = f'PERUN_{module_name.upper()}_SOURCES'
    pch_variable_name = f'PERUN_PCH'
    output_cmake_sources_file_path = module_path / 'CMakeSources.txt'

    with output_cmake_sources_file_path.open(mode='w', encoding="utf-8") as f:
        f.write(
            '#\n# Autogenerated list of main source files\n# Use collect_sources.py script for regenerate it\n#\n\n')
        write_sources(main_variable_name, main_sources)

        if pch_sources:
            f.write('\n')
            write_sources(pch_variable_name, pch_sources)


if __name__ == '__main__':
    logging.basicConfig(stream=sys.stdout, level=logging.INFO)
    root_path = Path(__file__).absolute().parent.parent

    for module in modules:
        logger.info('Process: %s', module)

        module_path = Path(root_path / module)
        module_name = Path(module).name

        main_sources, pch_sources = collect_sources(module_path)
        write_cmake_source_files(module_name, module_path, main_sources, pch_sources)

    logger.info('Ok')
