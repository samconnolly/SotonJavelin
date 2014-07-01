#!/usr/bin/env python

from numpy.distutils.core import setup

setup(  version="0.3alpha - soton 1.0",
        description="sotonjavelin: Just Another Vehicle for Estimting Lags In Nuclei (Southampton Version)",
        author="Ying Zu",
        author_email="zuying@gmail.com ",
        url="https://bitbucket.org/nye17/sotonjavelin",
        maintainer="Sam Connolly",
        maintainer_email="sdc1g08@soton.ac.uk",
        license="Academic Free License",
        classifiers=[
            'Development Status :: 5 - Production/Stable',
            'Environment :: Console',
            'Operating System :: OS Independent',
            'Intended Audience :: Science/Research',
            'License :: OSI Approved :: Academic Free License (AFL)',
            'Programming Language :: Python',
            'Programming Language :: Fortran',
            'Topic :: Scientific/Engineering',
             ],
        cmdclass = {
            # Use our customized commands
            'clean': MyClean,
            },
        requires=['NumPy (>=1.3)',],
        long_description="""
        Ongoing effort to combine an integral GP module to the AGN variablility study.
        """,
        packages=["sotonjavelin", 
                  "sotonjavelin/gp", 
                  "sotonjavelin/gp/cov_funs",
                  "sotonjavelin/emcee",
                  ],
        **(config_dict)
        )
