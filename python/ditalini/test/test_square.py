import ditalini


def test_square():
    sim = ditalini.Simulation(2.0)
    assert sim.square() == 4.0
