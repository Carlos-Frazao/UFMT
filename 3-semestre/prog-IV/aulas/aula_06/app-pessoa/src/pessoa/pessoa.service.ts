import { Injectable, NotFoundException } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { Pessoa } from './entities/pessoa.entity';
import { CreatePessoaDto } from './dto/create-pessoa.dto';
import { UpdatePessoaDto } from './dto/update-pessoa.dto';

@Injectable()
export class PessoaService {
  constructor(
    @InjectRepository(Pessoa)
    private pessoaRepository: Repository<Pessoa>,
  ) {}

  async create(createPessoaDto: CreatePessoaDto): Promise<Pessoa> {
    const pessoa = this.pessoaRepository.create(createPessoaDto);
    return this.pessoaRepository.save(pessoa);
  }

  async findAll(): Promise<Pessoa[]> {
    return this.pessoaRepository.find({
      order: { criadoEm: 'DESC' },
    });
  }

  async findOne(id: number): Promise<Pessoa> {
    const pessoa = await this.pessoaRepository.findOneBy({ id });
    if (!pessoa) {
      throw new NotFoundException(`Pessoa com ID ${id} não encontrada`);
    }
    return pessoa;
  }

  async update(id: number, updatePessoaDto: UpdatePessoaDto): Promise<Pessoa> {
    const pessoa = await this.findOne(id);
    Object.assign(pessoa, updatePessoaDto);
    return this.pessoaRepository.save(pessoa);
  }

  async remove(id: number): Promise<{ message: string }> {
    const pessoa = await this.findOne(id);
    await this.pessoaRepository.delete(id);
    return { message: `Pessoa com ID ${id} deletada com sucesso` };
  }
}
